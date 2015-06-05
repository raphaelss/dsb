#include <iostream>
#include <vector>
#include "parameter.hpp"
#include <memory>
#include "block.hpp"

int main() {
  dsb::block<1, 1, dsb::bypass> block(0u);
  const std::unique_ptr<dsb::bypass> b = std::make_unique<dsb::bypass>(0);
  std::cout << b->name() << std::endl;
  std::cout << b->description() << std::endl;
  return 0;
}
