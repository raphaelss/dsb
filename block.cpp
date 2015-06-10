#include <algorithm>
#include "block.hpp"

namespace sblocks {

block::block(unsigned input_n, unsigned output_n,
    std::vector<std::unique_ptr<parameter>> parameters): _inputs(input_n),
        _outputs(output_n), _parameters(std::move(parameters)) {}

std::shared_ptr<block> block::copy() const {
  std::vector<std::unique_ptr<parameter>> param_vec(_parameters.size());
  std::transform(_parameters.cbegin(), _parameters.cend(), param_vec.begin(),
      [](const std::unique_ptr<parameter> &ptr) {
        return ptr->copy();
      });
  return std::make_shared<block>(_inputs.size(), _outputs.size(),
      std::move(param_vec));
}

}
