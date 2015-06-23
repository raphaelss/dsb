#ifndef BLOCK_DESCRIPTOR_HPP_STOMPBLOCKS_INCLUDED
#define  BLOCK_DESCRIPTOR_HPP_STOMPBLOCKS_INCLUDED
#include <string>
#include <memory>
#include <vector>
#include "parameter.hpp"

namespace sblocks {

class block_descriptor : public descriptor {
public:
  block_descriptor(std::string name, std::string descr, unsigned input_n,
      unsigned output_n, std::vector<std::unique_ptr<parameter>> params);

  unsigned input_n() const;
  unsigned output_n() const;

  std::vector<std::unique_ptr<parameter>> parameter_vector_copy() const;

private:
  unsigned _input_n, _output_n;
  std::vector<std::unique_ptr<parameter>> _parameters;
};

}

#endif
