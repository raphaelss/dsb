#include <iostream>
#include <vector>
#include "block_descriptor.hpp"

int main() {
  std::vector<dsb::block_descriptor> blocks(
      dsb::load_block_descriptors("../blocks.xml")
  );
  return 0;
}
