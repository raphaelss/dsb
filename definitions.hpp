#ifndef DEFINITIONS_HPP_INCLUDED
#define DEFINITIONS_HPP_INCLUDED
#include <istream>
#include "parameter_descriptor.hpp"
#include "block_descriptor.hpp"
#include "block.hpp"

namespace sblocks {

class definition_handler {
public:
  definition_handler(std::istream &in);

private:
  std::vector<std::unique_ptr<parameter_descriptor>> _parameter_descriptors;
  std::vector<block_descriptor> _block_descriptors;
};

}

#endif
