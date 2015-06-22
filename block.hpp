#ifndef BLOCK_HPP_STOMPBLOCKS_INCLUDED
#define BLOCK_HPP_STOMPBLOCKS_INCLUDED
#include <vector>
#include <memory>
#include "parameter.hpp"
#include "block_descriptor.hpp"

namespace sblocks {

class block : public describable {
public:
  using iterator = std::vector<std::unique_ptr<parameter>>::iterator;
  using const_iterator =
      std::vector<std::unique_ptr<parameter>>::const_iterator;

  block(const block_descriptor &descr);

  std::shared_ptr<block> copy() const;

  const std::string &name() const override;
  const std::string &description () const override;

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

private:
  block(unsigned input_n, unsigned output_n,
       std::vector<std::unique_ptr<parameter>> parameters);

  const block_descriptor *_descriptor;
  std::vector<std::unique_ptr<parameter>> _parameters;
};

}

#endif
