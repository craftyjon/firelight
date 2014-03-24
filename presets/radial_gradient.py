import random
import math
import numpy as np

from preset import Preset
from parameter import Parameter
from utils import clip


class RadialGradient(Preset):
    """Radial gradient that responds to onsets"""

    speed = Parameter('speed', 0.1)
    hue_width = Parameter('hue-width', 0.2)
    hue_step = Parameter('hue-step', 0.1)
    wave1_amplitude = Parameter('wave1-amplitude', 0.4)
    wave1_period = Parameter('wave1-period', 2.5)
    wave1_speed = Parameter('wave1-speed', 0.02)
    wave2_amplitude = Parameter('wave2-amplitude', 0.3)
    wave2_period = Parameter('wave2-period', 3.0)
    wave2_speed = Parameter('wave2-speed', -1.0)
    #blackout = Parameter('blackout', 0.05)
    blackout = Parameter('blackout', 0.6)
    #whiteout = Parameter('whiteout', 0.1)
    whiteout = Parameter('whiteout', 0)
    luminance_speed = Parameter('luminance-speed', 0.25)
    luminance_scale = Parameter('luminance-scale', 1.5)

    luminance_steps = Parameter('luminance-steps', 256)

    def editable_parameters(self):
        return [
            self.speed,
            self.hue_width,
            self.hue_step,
            self.wave1_amplitude,
            self.wave1_speed,
            self.wave1_period,
            self.wave2_amplitude,
            self.wave2_period,
            self.wave2_speed,
            self.blackout,
            self.whiteout,
            self.luminance_speed,
            self.luminance_scale
        ]

    def on_load(self):
        #cx, cy = self.scene().center_point()
        cx, cy = self.center_point()

        self.locations = self.get_locations_buffer()
        x, y = self.locations.T
        x -= cx
        y -= cy
        self.pixel_distances = np.sqrt(np.square(x) + np.square(y))
        self.pixel_angles = math.pi + np.arctan2(y, x)
        self.pixel_distances /= max(self.pixel_distances)

    def prepare(self):
        self.hue_inner = random.random()
        self.wave1_offset = random.random()
        self.wave2_offset = random.random()
        self.luminance_offset = random.random()

    def draw(self, dt):

        #if self._mixer.is_onset():
        #    self.hue_inner = math.fmod(self.hue_inner + self.hue-step(), 1.0)
        #    self.luminance_offset += self.hue-step()

        self.hue_inner += dt * self.speed()
        self.wave1_offset += self.wave1_speed() * dt
        self.wave2_offset += self.wave2_speed() * dt
        self.luminance_offset += self.luminance_speed() * dt

        luminance_table = []
        luminance = 0.0
        for input in range(self.luminance_steps()):
            if input > self.blackout() * self.luminance_steps():
                luminance -= 0.01
                luminance = clip(0, luminance, 1.0)
            elif input < self.whiteout() * self.luminance_steps():
                luminance += 0.1
                luminance = clip(0, luminance, 1.0)
            else:
                luminance -= 0.01
                luminance = clip(0.5, luminance, 1.0)
            luminance_table.append(luminance)
        luminance_table = np.asarray(luminance_table)

        wave1_period = self.wave1_period()
        wave1_amplitude = self.wave1_amplitude()
        wave2_period = self.wave2_period()
        wave2_amplitude = self.wave2_amplitude()
        luminance_scale = self.luminance_scale()

        wave1 = np.abs(np.cos(self.wave1_offset + self.pixel_angles * wave1_period) * wave1_amplitude)
        wave2 = np.abs(np.cos(self.wave2_offset + self.pixel_angles * wave2_period) * wave2_amplitude)
        hues = self.pixel_distances + wave1 + wave2

        luminance_indices = np.mod(np.abs(np.int_((self.luminance_offset + hues * luminance_scale) * self.luminance_steps())), self.luminance_steps())
        luminances = luminance_table[luminance_indices]
        hues = np.fmod(self.hue_inner + hues * self.hue_width(), 1.0)

        self.setAllHLS(hues, luminances, 1.0)
