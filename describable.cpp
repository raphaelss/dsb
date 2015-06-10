#include "describable.hpp"
#include <algorithm>

namespace sblocks {

descriptor::descriptor(std::string name_arg, std::string descr)
    : _name(std::move(name_arg)), _description(std::move(descr)) {}

const std::string &descriptor::name() const {
  return _name;
}

const std::string &descriptor::description() const {
  return _description;
}

}
