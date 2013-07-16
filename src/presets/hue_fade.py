"""
Hue Fade
"""
from Firelight import Preset
from Firelight import Scene


class HueFade(Preset):

	def on_load(self):
		print "HueFade.on_load()"

	def prepare(self):
		print "HueFade.prepare()"

	def draw(self):
		print "HueFade.draw()"