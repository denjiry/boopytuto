#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
//#pragma GCC diagnostic pop

namespace p = boost::python;
namespace np = boost::python::numpy;

np::ndarray test() {
  p::tuple shape = p::make_tuple(3, 3);
  np::dtype dtype = np::dtype::get_builtin<float>();
  np::ndarray a = np::zeros(shape, dtype);
  return a;
}
struct World
{
  World(np::ndarray narr): narr(narr) {}//add constructor
  void set(np::ndarray narr) { this->narr = narr; }
  np::ndarray greet() { return narr; }
  np::ndarray narr;
};

BOOST_PYTHON_MODULE(tnum)
{
  //Py_Initialize();
  np::initialize();
  p::def("test", test);

  p::class_<World>("World", p::init<np::ndarray>())
    .def("greet", &World::greet)
    .def("set", &World::set)
    ;
}
