"""
Hue Fade
"""
from Firelight import Preset
from Firelight import Scene


class HueFade(Preset):

	def on_load():
		print "HueFade.on_load()"

	def prepare():
		print "HueFade.prepare()"

	def draw():
		print "HueFade.draw()"