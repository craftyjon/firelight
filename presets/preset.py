"""
Firelight
Copyright (c) 2013 Jon Evans

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
"""

import json
import numpy as np


class Preset:

    parameter_table = {}
    
    def __init__(self):
        pass

    def on_load(self):
        """
        This method is called when the preset is reloaded.
        Use for one-time initialization.
        """
        pass

    def prepare(self):
        """
        This method is called before the preset is about to become active.
        Use for resetting random variables, etc.
        """
        pass

    def draw(self, dt):
        """
        Override this method to design the preset.
        """
        raise NotImplementedError("You must override the draw method!")

    def editable_parameters(self):
        """
        Returns a list of parameters that should be exposed to the GUI
        """
        return []

    def get_buffer(self):
        """
        Returns the framebuffer to C++ host
        """
        return self._frameBuffer

    def clear_buffer(self):
        """
        Clears the framebuffer
        """
        self.setAllHLS(0, 0, 0)

    def get_parameters(self):
        """
        Returns the parameter table to the C++ host
        """
        ps = ",".join([repr(p) for p in self.editable_parameters()])
        return "[%s]" % ps

    def get_parameter_by_name(self, pname):
        plist = [p for p in self.editable_parameters() if p.key == pname]
        if len(plist) > 0:
            return plist[0]
        else:
            raise ValueError("No parameter by the name %s" % pname)

    def set_parameters(self, pars):
        """
        Reloads the parameter table using a JSON dictionary.
        """
        for pdata in json.loads(pars):
            try:
                par = self.get_parameter_by_name(pdata['key'])
                par.fromJSON(pdata)
            except ValueError:
                continue

    def set_output_size(self, width, height):
        """
        Sets the size of the framebuffer and initializes it
        """
        self._outputWidth = width
        self._outputHeight = height

        self._frameBuffer = np.zeros((width * height, 3), dtype=np.float32)

    def create_channel_buffer(self):
        return np.zeros((self._outputWidth * self._outputHeight), dtype=np.float32)

    def dimensions(self):
        return (self._outputWidth, self._outputHeight)

    def center_point(self):
        return (self._outputWidth / 2.0, self._outputHeight / 2.0)

    def get_locations_buffer(self):
        """
        Returns a buffer of location points for modification by the preset.
        TODO: This is a silly way to operate, but in the interest of prototyping rapidly, I am doing it anyway
        """
        arr = np.zeros((self._outputWidth, self._outputHeight, 2), dtype=np.float32)
        it = np.nditer(arr, flags=['multi_index'], op_flags=['writeonly'])
        while not it.finished:
            if it.multi_index[2] == 0:
                it[0] = it.multi_index[0]
            else:
                it[0] = it.multi_index[1]
            it.iternext()

        return arr.reshape((self._outputWidth * self._outputHeight), 2)

    def setAllHLS(self, hues, luminances, saturations):
        """
        Sets the entire buffer, assuming an input list.
        """
        self._frameBuffer[:,0] = hues
        self._frameBuffer[:,1] = luminances
        self._frameBuffer[:,2] = saturations