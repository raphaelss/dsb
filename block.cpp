#include <algorithm>
#include "block.hpp"

namespace sblocks {

static block::block_iterator find_first_null(
    std::vector<std::shared_ptr<block>> &vec) {
  return std::find_if(vec.begin(), vec.end(), [](std::shared_ptr<block> &ptr) {
    return !static_cast<bool>(ptr);
  });
}

block::block(const block_descriptor &descr): _descriptor(&descr),
    _inputs(descr.input_n()), _outputs(descr.output_n()),
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

block::block_iterator block::input_begin() {
  return _inputs.begin();
}

block::block_iterator block::input_end() {
  return _inputs.end();
}

block::block_iterator block::output_begin() {
  return _outputs.begin();
}

block::block_iterator block::output_end() {
  return _outputs.end();
}

block::param_iterator block::param_begin() {
  return _parameters.begin();
}

block::param_iterator block::param_end() {
  return _parameters.end();
}

block::block_iterator block::input_first_free() {
  return find_first_null(_inputs);
}

block::block_iterator block::output_first_free() {
  return find_first_null(_outputs);
}


}
