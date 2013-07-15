#include <Python.h>
#include <boost/python.hpp>
#include <boost/filesystem.hpp>

#include "preset_helper.h"

using namespace boost::python;
using namespace boost::filesystem;


int main(int, char **) {

  Py_Initialize();

  // Add our CWD to the Python path
  path cwd = complete("./").normalize();
  PyObject* pythonPath = PySys_GetObject("path");
  PyList_Insert(pythonPath, 0, PyString_FromString(cwd.string().c_str()));

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