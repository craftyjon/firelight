"""
Hue Fade
"""
from firelight import Preset
from firelight import Scene


class HueFade(FirelightPreset):
	def setup():
		str = "Extents: ", Scene.extents()
		return str

	def draw(dt):
		pass