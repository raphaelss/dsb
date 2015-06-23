#include "block_descriptor.hpp"
#include <algorithm>

namespace sblocks {

block_descriptor::block_descriptor(std::string name, std::string descr,
    unsigned input_n, unsigned output_n,
    std::vector<std::unique_ptr<parameter>> parameters)
        : descriptor(std::move(name), std::move(descr)), _input_n(input_n),
        _output_n(output_n), _parameters(std::move(parameters)) {}

unsigned block_descriptor::input_n() const {
  return _input_n;
}

unsigned block_descriptor::output_n() const {
  return _output_n;
}

std::vector<std::unique_ptr<parameter>>
block_descriptor::parameter_vector_copy() const {
  std::vector<std::unique_ptr<parameter>> param_vec(_parameters.size());
  std::transform(_parameters.cbegin(), _parameters.cend(), param_vec.begin(),
      [](const std::unique_ptr<parameter> &ptr) {
        return ptr->copy();
      });
  return std::move(param_vec);
}

}
