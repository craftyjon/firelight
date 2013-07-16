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