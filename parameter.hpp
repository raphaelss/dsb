#ifndef PARAMETER_HPP_STOMPBLOCKS_INCLUDED
#define PARAMETER_HPP_STOMPBLOCKS_INCLUDED
#include <memory>
#include "describable.hpp"

namespace sblocks {

class parameter_descriptor;
class switch_parameter_descriptor;
class number_parameter_descriptor;
struct parameter_visitor;

struct parameter : describable {
  const std::string &name() const override;
  const std::string &description() const override;

  virtual const parameter_descriptor &get_descriptor() const = 0;
  virtual std::unique_ptr<parameter> copy() const = 0;
  virtual void accept(parameter_visitor &visitor) = 0;
};

class switch_parameter : public parameter {
public:
  switch_parameter(const switch_parameter_descriptor &descr);

  const parameter_descriptor &get_descriptor() const override;
  std::unique_ptr<parameter> copy() const override;
  void accept(parameter_visitor &visitor) override;

  const std::string &at(unsigned i) const;
  void set(unsigned x);
  unsigned size() const;

private:
  unsigned _index;
  const switch_parameter_descriptor *_descriptor;
};

class number_parameter : public parameter {
public:
  number_parameter(const number_parameter_descriptor &descr);

  const parameter_descriptor &get_descriptor() const override;
  std::unique_ptr<parameter> copy() const override;
  void accept(parameter_visitor &visitor) override;

  double value() const;
  void set(double x);

private:
  double _value;
  const number_parameter_descriptor *_descriptor;
};

struct parameter_visitor {
  virtual ~parameter_visitor() = default;
  virtual void visit(switch_parameter &p) = 0;
  virtual void visit(number_parameter &p) = 0;
};

}

#endif
