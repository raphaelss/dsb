#include <algorithm>
#include "block.hpp"

namespace sblocks {

block::block(const block_descriptor &descr): _descriptor(&descr),
    _parameters(std::move(descr.parameter_vector_copy())) {}

const std::string &block::name() const {
  return _descriptor->description();
}

const std::string &block::description () const {
  return _descriptor->description();
}

unsigned block::input_n() const {
  return _descriptor->input_n();
}

unsigned block::output_n() const {
  return _descriptor->output_n();
}

/*
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
*/

}
