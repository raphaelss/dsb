#ifndef BLOCK_HPP_STOMPBLOCKS_INCLUDED
#define BLOCK_HPP_STOMPBLOCKS_INCLUDED
#include <vector>
#include <memory>
#include "parameter.hpp"
#include "block_descriptor.hpp"

namespace sblocks {

class block : public describable {
public:
  using block_iterator = std::vector<std::shared_ptr<block>>::iterator;
  using param_iterator = std::vector<std::unique_ptr<parameter>>::iterator;

  block(const block_descriptor &descr);

  std::shared_ptr<block> copy() const;

  const std::string &name() const override;
  const std::string &description () const override;

  block_iterator input_begin();
  block_iterator input_end();
  block_iterator output_begin();
  block_iterator output_end();
  param_iterator param_begin();
  param_iterator param_end();

  block_iterator input_first_free();
  block_iterator output_first_free();

private:
  block(unsigned input_n, unsigned output_n,
       std::vector<std::unique_ptr<parameter>> parameters);

  const block_descriptor *_descriptor;
  std::vector<std::shared_ptr<block>> _inputs;
  std::vector<std::shared_ptr<block>> _outputs;
  std::vector<std::unique_ptr<parameter>> _parameters;
};

}

#endif
