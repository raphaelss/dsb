#include <iostream>
#include <vector>
#include "definitions.hpp"
#include "block.hpp"
#include "patcher.hpp"

int main() {
  sblocks::definition_handler dh(std::cin);
  std::vector<sblocks::block> blocks;
  for (auto it = dh.cbegin(); it != dh.cend(); ++it) {
    blocks.emplace_back(*it);
  }
  sblocks::patcher(blocks);
  return 0;
}
