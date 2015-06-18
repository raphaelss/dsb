#include "parameter_descriptor.hpp"
#include <algorithm>
#include "parameter.hpp"

namespace sblocks {

parameter_descriptor::parameter_descriptor(std::string name,
    std::string descr): descriptor(std::move(name), std::move(descr)) {}

switch_parameter_descriptor::switch_parameter_descriptor(std::string name,
    std::string descr, std::vector<std::string> options_)
        : parameter_descriptor(std::move(name), std::move(descr)),
          options(std::move(options_)) {}

std::unique_ptr<parameter> switch_parameter_descriptor::instantiate() const {
  return std::move(std::unique_ptr<parameter>(new switch_parameter(*this)));
}

void switch_parameter_descriptor::accept(
    parameter_descriptor_visitor &visitor) const {
  visitor.visit(*this);
}

number_parameter_descriptor::number_parameter_descriptor(std::string name,
    std::string descr, double min_, double max_)
        : parameter_descriptor(std::move(name), std::move(descr)), min(min_),
          max(max_) {}

std::unique_ptr<parameter> number_parameter_descriptor::instantiate() const {
  return std::move(std::unique_ptr<parameter>(new number_parameter(*this)));
}

void number_parameter_descriptor::accept(
    parameter_descriptor_visitor &visitor) const {
  visitor.visit(*this);
}

}
