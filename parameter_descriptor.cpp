#include "parameter_descriptor.hpp"

namespace dsb {

parameter_descriptor::parameter_descriptor() {}

const std::string &parameter_descritpor::label() const {
  return _label;
}

const std::string &parameter_descriptor::description() const {
  return _description;
}

parameter_type parameter_descriptor::type() const {
  return _type;
}

}
