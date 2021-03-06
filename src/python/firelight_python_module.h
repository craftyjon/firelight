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

#ifndef _FIRELIGHT_PYTHON_MODULE_H
#define _FIRELIGHT_PYTHON_MODULE_H

#include <boost/python.hpp>

#include "preset.h"
#include "scene.h"
#include "parameters.h"

namespace bp = boost::python;

namespace firelight { namespace python {

BOOST_PYTHON_MODULE(Firelight)
{
    bp::class_<Preset, boost::noncopyable>("Preset", bp::init<>())
            .def("set_output_size", &Preset::setOutputSize)
            .def_readonly("outputHeight", &Preset::outputHeight)
            .def_readonly("outputWidth", &Preset::outputWidth);
    bp::class_<Scene>("Scene", bp::no_init);

 //   bp::scope Parameters = bp::class_<ParametersWrapper>("Parameters");
 //   bp::class_<Parameters::FloatParameter>("FloatParameter", bp::no_init);
}

}}

#endif
