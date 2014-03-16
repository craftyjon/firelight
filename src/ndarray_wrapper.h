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
//
// Adapted from example code written by Øystein Skotheim
// http://www.edge.no/wiki/NumPyArrayData

#ifndef NDARRAY_WRAPPER_H
#define NDARRAY_WRAPPER_H

#include <boost/python.hpp>
#include <boost/numpy.hpp>

namespace bp = boost::python;
namespace np = boost::numpy;

template<typename T> class NDArrayWrapper
{
public:
    NDArrayWrapper<T>(const np::ndarray &arr)
    {
        _data = arr.get_data();
        _strides = arr.get_strides();
    }

    T* data()
    {
        return reinterpret_cast<T*>(_data);
    }

    const Py_intptr_t* strides()
    {
        return _strides;
    }

    // 1D array access
    inline T& operator()(int i)
    {
        return *reinterpret_cast<T*>(_data + i * _strides[0]);
    }

    // 2D array access
    inline T& operator()(int i, int j)
    {
        return *reinterpret_cast<T*>(_data + i * _strides[0] + j * _strides[1]);
    }

    // 3D array access
    inline T& operator()(int i, int j, int k)
    {
        return *reinterpret_cast<T*>(_data + i * _strides[0] + j * _strides[1] + k * _strides[2]);
    }

private:
    char* _data;
    const Py_intptr_t* _strides;
};

#endif // NDARRAY_WRAPPER_H
