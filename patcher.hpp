#ifndef PATCHER_HPP_STOMPBLOCKS_INCLUDED
#define PATCHER_HPP_STOMPBLOCKS_INCLUDED
#include "definitions.hpp"
#include "block.hpp"

namespace sblocks {

class patcher {
public:
  patcher(const definition_handler &descriptors);


private:
  const definition_handler *_descriptors;
};

}

#endif
