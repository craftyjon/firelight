#include <Python.h>
#include <boost/python.hpp>
#include <boost/filesystem.hpp>

#include "preset_helper.h"

using namespace boost::python;


int main(int, char **) {

  Py_Initialize();

  // now time to insert the current working directory into the python path so module search can take advantage
  // this must happen after python has been initialised
  boost::filesystem::path workingDir = boost::filesystem::complete("./").normalize();
  PyObject* sysPath = PySys_GetObject("path");
  PyList_Insert( sysPath, 0, PyString_FromString(workingDir.string().c_str()));

  // Setup helper modules
  initFirelightScene();

  try {  

    

    object hue_fade = import("src.presets.hue_fade");
    //PyRun_SimpleString("import FirelightScene");

    hue_fade.attr("setup")();

  } catch (error_already_set) {
    PyErr_Print();
  }

  return 0;
}