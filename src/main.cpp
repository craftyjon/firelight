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

#include <boost/python.hpp>
#include <boost/filesystem.hpp>

#include <QDebug>
#include <QString>
#include <QApplication>

#include "firelight_scene.h"
#include "ui/firelight_main.h"
#include "util/boost_python_qstring.h"

namespace bp = boost::python;


int main(int argc, char **argv) {

	Py_Initialize();

	// Add our CWD to the Python path
	boost::filesystem::path cwd = boost::filesystem::complete("./src/presets").normalize();
	qDebug("Our path is %s", cwd.string().c_str());
	PyObject* pythonPath = PySys_GetObject("path");
	PyList_Insert(pythonPath, 0, PyString_FromString(cwd.string().c_str()));

	// Setup helper modules
	initFirelightScene();
    initBoostPythonQString();

	QString result;

	try {
		bp::object hue_fade = bp::import("hue_fade");

		try {
			result = bp::extract<QString>(hue_fade.attr("setup")());
			
        } catch (bp::error_already_set) {
			qDebug() << "Setup of preset failed.";
			PyErr_Print();
		}  
	} catch (bp::error_already_set) {
		qDebug() << "Failed to import preset.";
		PyErr_Print();
	}

	qDebug() << result;

	QApplication app(argc, argv);
	FirelightMain *mainWindow = new FirelightMain;

	mainWindow->show();
	return app.exec();
}