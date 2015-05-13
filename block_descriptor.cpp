#include "block_descriptor.hpp"
#include <algorithm>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace dsb {

namespace pt = boost::property_tree;

unsigned block_descriptor::n_parameter() const {
  return _parameters.size();
}

unsigned block_descriptor::n_input() const {
  return _input_labels.size();
}

unsigned block_descriptor::n_output() const {
  return _output_labels.size();
}

const parameter_descriptor &block_descriptor::parameter(unsigned i) const {
  return _parameters[i];
}

const std::string &block_descriptor::input_label(unsigned i) const {
  return _input_labels[i];
}

const std::string &block_descriptor::output_label(unsigned i) const {
  return _output_labels[i];
}

std::vector<block_descriptor> load_block_descriptors(const std::string &path) {
  std::vector<block_descriptor> vec;
  std::string name, description;
  std::vector<std::string> inputs, outputs;
  std::vector<parameter_descriptor> params;
  pt::ptree tree;
  pt::read_xml(path, tree);
  return std::move(vec);
}

}
