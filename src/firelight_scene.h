#include <boost/python.hpp>

namespace bp = boost::python;

namespace firelight {
namespace python_modules {
namespace scene {

PyObject* extents(void) {
	PyObject *e = PyTuple_New(2);
	e = Py_BuildValue("ii", 640, 480);
	return e;
}

}}} // Namespace firelight::python_modules::scene


BOOST_PYTHON_MODULE(FirelightScene)
{
    bp::def("extents", firelight::python_modules::scene::extents);
}