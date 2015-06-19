#include "parameter.hpp"
#include "parameter_descriptor.hpp"

namespace sblocks {

const std::string &parameter::name() const {
  return get_descriptor().name();
}

const std::string &parameter::description() const {
  return get_descriptor().description();
}

switch_parameter::switch_parameter(const switch_parameter_descriptor &descr)
    : _index(0), _descriptor(descr) {}

const parameter_descriptor &switch_parameter::get_descriptor() const {
  return _descriptor;
}

std::unique_ptr<parameter> switch_parameter::copy() const {
  auto ptr = new switch_parameter(_descriptor);
  ptr->_index = _index;
  return std::unique_ptr<parameter>(ptr);
}

void switch_parameter::accept(parameter_visitor &visitor) {
  visitor.visit(*this);
}

void switch_parameter::set_value(unsigned x) {
  if (x >= _descriptor.options.size())
    throw 2.0;
  _index = x;
}

number_parameter::number_parameter(const number_parameter_descriptor &descr)
    : _value(descr.min), _descriptor(descr) {}

const parameter_descriptor &number_parameter::get_descriptor() const {
  return _descriptor;
}

std::unique_ptr<parameter> number_parameter::copy() const {
  auto ptr = new number_parameter(_descriptor);
  ptr->_value = _value;
  return std::unique_ptr<parameter>(ptr);
}

void number_parameter::accept(parameter_visitor &visitor) {
  visitor.visit(*this);
}

void number_parameter::set_value(double x) {
  if (x < _descriptor.min || x > _descriptor.max)
    throw 2.0;
  _value = x;
}

}
