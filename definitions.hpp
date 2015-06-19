#ifndef DEFINITIONS_HPP_INCLUDED
#define DEFINITIONS_HPP_INCLUDED
#include <istream>
#include "parameter_descriptor.hpp"
#include "block_descriptor.hpp"

namespace sblocks {

class definition_handler {
public:
  using const_iterator = std::vector<block_descriptor>::const_iterator;

  definition_handler(std::istream &in);

  const_iterator cbegin() const;
  const_iterator cend() const;

private:
  std::vector<std::unique_ptr<parameter_descriptor>> _parameter_descriptors;
  std::vector<block_descriptor> _block_descriptors;
};

}

#endif
