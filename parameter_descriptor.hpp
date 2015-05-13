#ifndef PARAMETER_DESCRIPTOR_HPP_DSPSTMPBX_INCLUDED
#define PARAMETER_DESCRIPTOR_HPP_DSPSTMPBX_INCLUDED
#include <string>

namespace dsb {

enum parameter_type {
  PARAMETER_NUMBER,
  PARAMETER_SWITCH
};

class parameter_descriptor {
public:
  parameter_descriptor();

  const std::string &label () const;
  const std::string &description () const;
  parameter_type type() const;


private:
  std::string _label;
  std::string _description;
  std::vector<std::string> _switch_tags;
};

}

#endif
