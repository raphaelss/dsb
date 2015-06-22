#include <algorithm>
#include "block.hpp"

namespace sblocks {

block::block(const block_descriptor &descr): _descriptor(&descr),
    _parameters(std::move(descr.parameter_vector_copy())) {}

std::shared_ptr<block> block::copy() const {
  return std::make_shared<block>(*_descriptor);
}

const std::string &block::name() const {
  return _descriptor->description();
}

const std::string &block::description () const {
  return _descriptor->description();
}

block::iterator block::begin() {
  return _parameters.begin();
}

block::iterator block::end() {
  return _parameters.end();
}

block::const_iterator block::cbegin() const {
  return _parameters.cbegin();
}

block::const_iterator block::cend() const {
  return _parameters.cend();
}


}
