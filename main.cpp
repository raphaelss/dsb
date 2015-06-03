#include <iostream>
#include <vector>
#include "parameter.hpp"

int main() {
  const dsb::parameter *b = dsb::bypass::default_instance();
  std::cout << b->name() << std::endl;
  std::cout << b->description() << std::endl;
  std::unique_ptr<dsb::parameter> ncb = b->copy();
  ncb->set_index(1);
  return 0;
}
