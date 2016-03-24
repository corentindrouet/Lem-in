#!/usr/bin/ruby
require 'gosu'

class Viewer < Gosu::Window
	def initialize
		super 640, 480
		self.caption = "Viewer Lem-in"
		@image = Gosu::Image.new("viewer_src/point.png")
	end
	def update
	end
	def draw(@x, @y)
		@image.draw(@x, @y, 0)
	end
end

window = Viewer.new

prout = gets
while (prout != "\n")
	
	prout = gets
end

window.show
