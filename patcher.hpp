#ifndef PATCHER_HPP_STOMPBLOCKS_INCLUDED
#define PATCHER_HPP_STOMPBLOCKS_INCLUDED
#include <vector>
#include <block>

namespace sblocks {

class patcher {
public:
  patcher(const std::vector<block> &blocks);


private:
  const std::vector<block> *_blocks;
};

};

#endif
