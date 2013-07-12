#include <boost/python.hpp>

using namespace boost::python;

namespace firelight {
namespace preset_helper {

int test(int x) {
  return x + 5;
}

}} // Namespace firelight::preset_helper

BOOST_PYTHON_MODULE(PresetHelper)
{
    def("test", firelight::preset_helper::test);
}