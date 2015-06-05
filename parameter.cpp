#include "parameter.hpp"

namespace dsb {

void parameter::set_index(unsigned i) {
  throw std::runtime_error("parameter does not respond to set_index.");
}

void parameter::set_number(double x) {
  throw std::runtime_error("parameter does not respond to set_number.");
}


}
