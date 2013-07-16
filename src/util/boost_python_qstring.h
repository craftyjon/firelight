// Example code by Austin Bingham
// http://misspent.wordpress.com/2009/09/27/how-to-write-boost-python-converters/

#ifndef _BOOST_PYTHON_QSTRING_H
#define _BOOST_PYTHON_QSTRING_H

#include <boost/python.hpp>
#include <QString>

struct QString_to_python_str
{
  static PyObject* convert(QString const& s)
  {
    return boost::python::incref(boost::python::object(s.toLatin1().constData()).ptr());
  }
};
 
struct QString_from_python_str
{
    QString_from_python_str()
    {
      boost::python::converter::registry::push_back(&convertible, &construct, boost::python::type_id<QString>());
    }
 
    // Determine if obj_ptr can be converted in a QString
    static void* convertible(PyObject* obj_ptr)
    {
        if (!PyString_Check(obj_ptr))
            return 0;
        return obj_ptr;
    }
 
    // Convert obj_ptr into a QString
    static void construct(PyObject* obj_ptr, boost::python::converter::rvalue_from_python_stage1_data* data)
    {
        // Extract the character data from the python string
        const char* value = PyString_AsString(obj_ptr);

        // Verify that obj_ptr is a string (should be ensured by convertible())
        assert(value);

        // Grab pointer to memory into which to construct the new QString
        void* storage = ((boost::python::converter::rvalue_from_python_storage<QString>*)data)->storage.bytes;

        // in-place construct the new QString using the character data
        // extraced from the python object
        new (storage) QString(value);

        // Stash the memory chunk pointer for later use by boost.python
        data->convertible = storage;
    }
};
 
void initBoostPythonQString()
{
  // register the to-python converter
  boost::python::to_python_converter<QString, QString_to_python_str>();
 
  // register the from-python converter
  QString_from_python_str();
}

#endif
