#include "block.hpp"

namespace dsb {

block::block(unsigned n_input, unsigned n_output)
    : inputs(n_input, nullptr), _outputs(n_output, nullptr) {}

}
