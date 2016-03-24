#!/usr/bin/ruby
require 'gosu'

class Viewer < Gosu::Window
	def initialize
		super 640, 480
		self.caption = "Viewer Lem-in"
		@background_image = Gosu::Image.new("space.png")
	end
	def update
	end
	def draw
		@background_image.draw(0, 0, 0)
	end
end

window = Viewer.new
window.show
