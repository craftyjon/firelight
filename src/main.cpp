#include <Python.h>
#include <boost/python.hpp>

#include "preset_helper.h"

using namespace boost::python;


int main(int, char **) {

  Py_Initialize(); 
  
  try {
    initPresetHelper();
  
    PyRun_SimpleString("import PresetHelper");
    PyRun_SimpleString("print PresetHelper.test(4)");
  } catch (error_already_set) {
    PyErr_Print();
  }
  
  Py_Finalize();
  return 0;
}