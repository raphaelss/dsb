#include <iostream>
#include "definitions.hpp"
#include "block.hpp"
#include "patcher.hpp"

int main() {
  sblocks::definition_handler dh(std::cin);
  sblocks::patcher p(dh);
  return 0;
}
