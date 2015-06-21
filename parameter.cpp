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
    : _index(0), _descriptor(&descr) {}

const parameter_descriptor &switch_parameter::get_descriptor() const {
  return *_descriptor;
}

std::unique_ptr<parameter> switch_parameter::copy() const {
  auto ptr = new switch_parameter(*_descriptor);
  ptr->_index = _index;
  return std::unique_ptr<parameter>(ptr);
}

void switch_parameter::accept(parameter_visitor &visitor) {
  visitor.visit(*this);
}

const std::string &switch_parameter::at(unsigned i) const {
  return _descriptor->options.at(i);
}

void switch_parameter::set(unsigned x) {
  if (x >= size())
    throw 2.0;
  _index = x;
}

unsigned switch_parameter::size() const {
  return _descriptor->options.size();
}

number_parameter::number_parameter(const number_parameter_descriptor &descr)
    : _value(descr.min), _descriptor(&descr) {}

const parameter_descriptor &number_parameter::get_descriptor() const {
  return *_descriptor;
}

std::unique_ptr<parameter> number_parameter::copy() const {
  auto ptr = new number_parameter(*_descriptor);
  ptr->_value = _value;
  return std::unique_ptr<parameter>(ptr);
}

void number_parameter::accept(parameter_visitor &visitor) {
  visitor.visit(*this);
}

double number_parameter::value() const {
  return _value;
}

void number_parameter::set(double x) {
  if (x < _descriptor->min || x > _descriptor->max)
    throw 2.0;
  _value = x;
}

}
