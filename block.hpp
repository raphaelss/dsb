#ifndef BLOCK_HPP_DSPSTMPBX_INCLUDED
#define BLOCK_HPP_DSPSTMPBX_INCLUDED
#include <array>
#include "parameter.hpp"
#include <boost/mpl/list.hpp>

namespace dsb {

namespace impl {

struct block_base {
  virtual ~block_base() = default;
};

template <class Iter>
void fill(Iter it) {}

template <class Iter, class T, class ...Rest>
void fill(Iter it, typename T::type arg, typename Rest::type... args) {
  *it++ = std::make_unique<T>(arg);
  fill(it, args...);
}

}

template<unsigned Nin, unsigned Nout, class ...Params>
class block : impl::block_base {
public:
  block(typename Params::type... args) {
    impl::fill<typename decltype(_params)::iterator, Params...>
        (_params.begin(), args...);
  }

private:
  std::array<std::shared_ptr<block_base>, Nin> _inputs;
  std::array<std::shared_ptr<block_base>, Nout> _outputs;
  std::array<std::unique_ptr<parameter>, sizeof...(Params)> _params;
};

}

#endif
