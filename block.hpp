#ifndef BLOCK_HPP_STOMPBLOCKS_INCLUDED
#define BLOCK_HPP_STOMPBLOCKS_INCLUDED
#include <vector>
#include <memory>
#include "parameter.hpp"
#include "block_descriptor.hpp"

namespace sblocks {

class block : public describable {
public:
  block(const block_descriptor &descr);

  const std::string &name() const override;
  const std::string &description () const override;

  unsigned input_n() const;
  unsigned output_n() const;

private:
  block(unsigned input_n, unsigned output_n,
       std::vector<std::unique_ptr<parameter>> parameters);

  const block_descriptor *_descriptor;
  std::vector<std::unique_ptr<parameter>> _parameters;
};

}

#endif
