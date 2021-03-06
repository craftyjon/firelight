// Firelight
// Copyright (c) 2013 Jon Evans
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef _PRESET_H
#define _PRESET_H

namespace firelight { namespace python {

class Preset
{
public:
    Preset() {}

    // Called once each time the preset is loaded.  Use for one-time initialization
    virtual void on_load(void) {};

    // Called once when a preset instance is about to go active.  Use for resetting random variables, etc
    virtual void prepare(void) {};

    // Called each tick to render the preset
    virtual void draw(void) {};

    // Set up parameters
    virtual void parameters(void) {};

    // Set up the size of the render target
    void setOutputSize(unsigned int width, unsigned int height);

    // These should all really be protected but can't figure out how to make that work yet
public:
    unsigned int outputWidth;
    unsigned int outputHeight;

};


void Preset::setOutputSize(unsigned int width, unsigned int height)
{
    outputWidth = width;
    outputHeight = height;
}


}}

#endif
