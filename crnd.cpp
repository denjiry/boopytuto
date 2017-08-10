#include <boost/python/numpy.hpp>
#include <iostream>

namespace p = boost::python;
namespace np= boost::python::numpy;

struct Var
{
  Var(std::string name):name(name),value(){}
  std::string const name;
  float value;
};

struct World
{
  World(std::string msg): msg(msg) {}//add constructor
  void set(std::string msg) { this->msg = msg; }
  std::string greet() { return msg; }
  std::string msg;
};

BOOST_PYTHON_MODULE(hello)
{
  class_<World>("World", init<std::string>())
    .def("greet", &World::greet)
    .def("set", &World::set)
    ;

  class_<Var>("Var", init<std::string>())
    .def_readonly("name",&Var::name)
    .def_readwrite("value",&Var::value)
    ;

}
