#!/usr/bin/ruby
require 'gosu'

class Viewer < Gosu::Window
	attr_accessor :x, :y, :t, :tun

	def initialize
		super 640, 480
		self.caption = "Viewer Lem-in"
		@x = 0
		@y = 0
	end
	def update
	end
	def draw
		i = 0
		while (t[i])
			draw_quad(t[i][1].to_i * 20, t[i][2].to_i * 20, 0xffff8888, (t[i][1].to_i * 20) + 20, (t[i][2].to_i * 20), 0xffff8888, (t[i][1].to_i * 20), (t[i][2].to_i * 20) + 20, 0xffff8888, (t[i][1].to_i * 20) + 20, (t[i][2].to_i * 20) + 20, 0xffff8888, 0)
			message = Gosu::Image.from_text(self, t[i][0], Gosu.default_font_name, 15)
			message.draw((t[i][1].to_i * 20) + 5, t[i][2].to_i * 20, 0)
			i += 1
		end
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
	end
end

window = Viewer.new

prout = gets
tab = []
tabtun = []
while (prout != "\n")
	if (prout[0] != '#')
		line = prout.split
		if (line[1])
			tab<<line
		else
			line = prout.split('-')
			if (line[1])
				tabtun<<line
			end
		end
	end
	prout = gets
end

				puts tabtun
window.t = tab
window.tun = tabtun
window.show
