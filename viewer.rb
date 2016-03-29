#!/usr/bin/ruby
require 'gosu'

class Viewer < Gosu::Window
	attr_accessor :x, :y, :t, :tun, :fourmis, :nb_f

	def initialize
		super 640, 480
		self.caption = "Viewer Lem-in"
		@f_img = Gosu::Image.new("viewer_src/fourmis.png")
		@x = 0
		@y = 0
		@fourmis = []
	end
	def update
		id = 0
		if (@x == 0 && Gosu::button_down?(Gosu::KbSpace))
			re = gets
			if (re != nil)
				re = re.chomp(" \n")
				line = re.split
				i = 0
				while (line[i])
					line[i].slice!("L")
					tmp = line[i].split("-")
					fourmis[tmp[0].to_i] = tmp[1]
					i += 1
				end
			end
		end
		@x += 1
		if (@x == 5)
			@x = 0
		end
	end
	def draw
		i = 0
		while (tun[i])
			j = 0
			while (t[j] && t[j][0] != tun[i][0])
				j += 1
			end
			k = 0
			while (t[k] && t[k][0] != tun[i][1])
				k += 1
			end
			if (t[j] && t[k])
				draw_line((t[j][1].to_i * 20) + 10, (t[j][2].to_i * 20) + 10, 0xffffffff, (t[k][1].to_i * 20) + 10, (t[k][2].to_i * 20) + 10, 0xffffffff)
			end
			i += 1
		end
		i = 0
		while (t[i])
			color = 0xff00ffff
			if (t[i] == "##start")
				i += 1
				color = 0xffff0000
			end
			if (t[i] == "##end")
				i += 1
				color = 0xff00ff00
			end
			draw_quad(t[i][1].to_i * 20, t[i][2].to_i * 20, color, (t[i][1].to_i * 20) + 20, (t[i][2].to_i * 20), color, (t[i][1].to_i * 20), (t[i][2].to_i * 20) + 20, color, (t[i][1].to_i * 20) + 20, (t[i][2].to_i * 20) + 20, color, 0)
			message = Gosu::Image.from_text(self, t[i][0], Gosu.default_font_name, 15)
			message.draw((t[i][1].to_i * 20) + 5, t[i][2].to_i * 20, 0)
			i += 1
		end
		i = 1
		while (i <= nb_f)
			if (fourmis[i])
				j = 0
				while (t[j][0] != fourmis[i])
					j += 1
				end
				@f_img.draw(t[j][1].to_i * 20, t[j][2].to_i * 20, 0)
			end
			i += 1
		end
	end
end

window = Viewer.new

prout = gets
if (prout == "Error\n")
	puts prout
	Process.exit!(true)
end
window.nb_f = prout.to_i
tab = []
tabtun = []
while (prout != "\n")
	prout = prout.chomp("\n")
	line = prout.split
	if (prout[0] == '#')
		tab<<prout
	elsif (line[1])
		tab<<line
	else
		line = prout.split('-')
		if (line[1])
			tabtun<<line
		end
	end
	prout = gets
end

window.t = tab
window.tun = tabtun
window.show
