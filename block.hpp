#ifndef BLOCK_HPP_DSPSTMPBX_INCLUDED
#define BLOCK_HPP_DSPSTMPBX_INCLUDED
#include <vector>

namespace dsb {

class block {
public:
	block(unsigned n_input, unsigned n_output);
	virtual ~block();
	virtual const char *label() const = 0;

private:
	std::vector<block*> inputs;
	std::vector<block*> outputs;
};

}

#endif
