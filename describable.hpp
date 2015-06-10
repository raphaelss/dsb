#ifndef DESCRIBABLE_HPP_STOMPBLOCKS_INCLUDED
#define DESCRIBABLE_HPP_STOMPBLOCKS_INCLUDED
#include <string>

namespace sblocks {

struct describable {
  virtual ~describable() = default;
  virtual const std::string &name() const = 0;
  virtual const std::string &description() const = 0;
};

class descriptor : public describable {
public:
  descriptor(std::string name_arg, std::string descr);

  const std::string &name() const override;
  const std::string &description() const override;

private:
  std::string _name;
  std::string _description;
};

}

#endif
