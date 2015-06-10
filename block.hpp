#ifndef BLOCK_HPP_STOMPBLOCKS_INCLUDED
#define BLOCK_HPP_STOMPBLOCKS_INCLUDED
#include <vector>
#include <memory>
#include "parameter.hpp"

namespace sblocks {

class block {
public:
  block(unsigned input_n, unsigned output_n,
       std::vector<std::unique_ptr<parameter>> parameters);

  std::shared_ptr<block> copy() const;

private:
  std::vector<std::shared_ptr<block>> _inputs;
  std::vector<std::shared_ptr<block>> _outputs;
  std::vector<std::unique_ptr<parameter>> _parameters;
};

}

#endif
