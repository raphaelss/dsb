#ifndef PARAMETER_DESCRIPTOR_HPP_STOMPBLOCKS_INCLUDED
#define PARAMETER_DESCRIPTOR_HPP_STOMPBLOCKS_INCLUDED
#include <string>
#include <vector>
#include <memory>
#include "describable.hpp"

namespace sblocks {

class parameter;

struct parameter_descriptor : descriptor {
  parameter_descriptor(std::string name, std::string descr);
  virtual std::unique_ptr<parameter> instantiate() const = 0;
};

struct switch_parameter_descriptor : parameter_descriptor {
  switch_parameter_descriptor(std::string name, std::string descr,
      std::vector<std::string> options_);

  std::unique_ptr<parameter> instantiate() const override;

  const std::vector<std::string> options;
};

struct number_parameter_descriptor : parameter_descriptor {
  number_parameter_descriptor(std::string name, std::string descr, double min_,
      double max_);

  std::unique_ptr<parameter> instantiate() const override;

  const double min, max;
};


}

#endif
