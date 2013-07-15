#include <boost/python.hpp>
#include <boost/filesystem.hpp>

#include <QDebug>
#include <QApplication>

#include "firelight_scene.h"
#include "ui/firelight_main.h"

using namespace boost::python;
using namespace boost::filesystem;


int main(int argc, char **argv) {

	Py_Initialize();

	// Add our CWD to the Python path
	path cwd = complete("./src/presets").normalize();
	qDebug("Our path is %s", cwd.string().c_str());
	PyObject* pythonPath = PySys_GetObject("path");
	PyList_Insert(pythonPath, 0, PyString_FromString(cwd.string().c_str()));

	// Setup helper modules
	initFirelightScene();

	try {
		object hue_fade = import("hue_fade");

		try {
			hue_fade.attr("setup")();
		} catch (error_already_set) {
			qDebug() << "Setup of preset failed.";
			PyErr_Print();
		}  
	} catch (error_already_set) {
		qDebug() << "Failed to import preset.";
		PyErr_Print();
	}

	QApplication app(argc, argv);
	FirelightMain *mainWindow = new FirelightMain;

	mainWindow->show();
	return app.exec();
}