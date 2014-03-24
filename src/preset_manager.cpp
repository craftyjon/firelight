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

#include <QDebug>
#include <QDir>
#include <QString>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "preset_manager.h"
#include "python/firelight_python_module.h"


// This is currently all a hack.

PresetManager::PresetManager()
{
    Py_Initialize();
    np::initialize();

    //stdout_buffer::initPythonStdout();
    //std::string python_console;
    //stdout_buffer::enablePythonStdout(&python_console)

    // Setup helper modules
    firelight::python::initFirelight();
    //initBoostPythonQString();

    // Add the preset folder to the Python path
    QString cwd = QDir("./presets").absolutePath();

    qDebug() << "Our path is" << cwd;
    PyObject* pythonPath = PySys_GetObject("path");
    PyList_Insert(pythonPath, 0, PyString_FromString(cwd.toStdString().c_str()));

    try {
        _classtype = bp::import("radial_gradient");

        try {
            _classinst = _classtype.attr("RadialGradient")();

            _classinst.attr("set_output_size")(320, 320);

            _classinst.attr("on_load")();

            _classinst.attr("prepare")();

            bp::str json = bp::call_method<bp::str>(_classinst.ptr(), "get_parameters");

            QString js = QString::fromUtf8(bp::extract<const char *>(json));
            QJsonDocument jd = QJsonDocument::fromJson(js.toUtf8());

            QJsonArray pars = jd.array();

            for (int i = 0; i < pars.size(); i++)
            {
                QJsonObject par = pars[i].toObject();
                if (par["key"].toString() == "speed")
                {
                    par["value"] = 0.14;
                    pars.replace(i, par);
                }

                if (par["key"].toString() == "luminance-speed")
                {
                    par["value"] = 0.25;
                    pars.replace(i, par);
                }
            }

            jd.setArray(pars);

            qDebug() << "params:" << jd.toJson();

            _classinst.attr("set_parameters")(((QString)jd.toJson()).toStdString().c_str());

        } catch (bp::error_already_set) {
            qDebug() << "Setup of preset failed.";
            PyErr_Print();
        }
    } catch (bp::error_already_set) {
        qDebug() << "Failed to import preset.";
        PyErr_Print();
    }
}


void PresetManager::tick()
{
    try {
        _classinst.attr("draw")(0.1);
        np::ndarray n = bp::call_method<np::ndarray>(_classinst.ptr(), "get_buffer");
        //qDebug() << bp::extract<char const*>(bp::str(n));
        emit frameReady(n);
    } catch (bp::error_already_set) {
        qDebug() << "Tick failed.";
    }
}

