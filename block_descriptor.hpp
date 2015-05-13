#ifndef BLOCK_DESCRIPTOR_HPP_DSPSTMPBX_INCLUDED
#define BLOCK_DESCRIPTOR_HPP_DSPSTMPBX_INCLUDED
#include <vector>
#include <string>
#include "parameter_descriptor.hpp"

namespace dsb {

class block_descriptor {
public:
  template <class Str = std::string, class Str_vec = std::vector<Str>,
            class Param_vec = std::vector<parameter_descriptor>>
  block_descriptor(Str &&name, Str &&description, Str_vec &&params,
                   Str_vec &&inputs, Str_vec &&outputs)
      : _name(name), _description(description), _parameters(params),
        _input_labels(inputs), _output_labels(outputs) {}

  unsigned n_parameter() const;
  unsigned n_input() const;
  unsigned n_output() const;

  const parameter_descriptor &parameter(unsigned i) const;
  const std::string &input_label(unsigned i) const;
  const std::string &output_label(unsigned i) const;

private:
  std::string _name;
  std::string _description;
  std::vector<parameter_descriptor> _parameters;
  std::vector<std::string> _input_labels;
  std::vector<std::string> _output_labels;
};

std::vector<block_descriptor> load_block_descriptors(const std::string &path);

}

#endif
