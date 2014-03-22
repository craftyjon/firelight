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

DTYPE_DOUBLE = 0
DTYPE_BOOL = 1
DTYPE_INT = 2
DTYPE_STR = 3


class Parameter:
    
    def __init__(self, key, default=0.0):
        self.key = key
        if type(default) == float:
            self.dtype = DTYPE_DOUBLE
        elif type(default) == str:
            self.dtype = DTYPE_STR
        elif type(default) == int:
            self.dtype = DTYPE_INT
        elif type(default) == bool:
            self.dtype = DTYPE_BOOL
        
        self.default = default
        self.value = default

    def __call__(self, *args, **kwargs):
        if len(args) == 0:
            return self.value
        else:
            if type(args[0]) == self.dtype:
                self.value = args[0]
            else:
                raise ValueError("%s is of type %s; cannot set to %s" % (self.key, str(self.dtype), str(args[0]) ) )

    def __repr__(self):
        """
        Serialize to JSON for host app
        """
        return json.dumps({'key': self.key,
                           'dtype': self.dtype,
                           'default': self.default,
                           'value': self.value})

    def fromJSON(self, json):
        """
        Deserialize
        """
        if json['key'] != self.key:
            raise ValueError("Key mismatch in fromJSON")
        self.value = json['value']