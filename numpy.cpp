#include <boost/python.hpp> 
#include <boost/python/numpy.hpp> 
#include<iostream>

namespace p = boost::python;
namespace np = boost::python::numpy;

np::ndarray test()
{
  p::tuple shape = p::make_tuple(3,3);
  np::dtype dtype = np::dtype::get_builtin<double>();
  np::ndarray a = np::zeros(shape, dtype);

  np::ndarray b = np::empty(shape, dtype);

  std::cout<<"Original array:\n" << p::extract<char const*>(p::str(a))<<std::endl;

  std::cout << "Datatype is:\n" << p::extract<char const*>(p::str(a.get_dtype()))<<std::endl;

  return a;
}

BOOST_PYTHON_MODULE(numtuto)
{
  Py_Initialize();
  np::initialize();
  p::def("test", test);
}
