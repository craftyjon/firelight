"""
Hue Fade
"""
from Firelight import Preset
from Firelight import Scene

import numpy as np


class HueFade(Preset):

    def on_load(self):
        print "HueFade.on_load()"

    def prepare(self):
        print "HueFade.prepare()"

    def draw(self):
        print "HueFade.draw()"
        array = np.eye(10, dtype=float)
        return array