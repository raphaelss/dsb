#ifndef PARAMETER_HPP_INCLUDED
#define PARAMETER_HPP_INCLUDED
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <memory>

namespace dsb {

struct parameter {
  virtual ~parameter() = default;

  virtual const std::string &name() const = 0;
  virtual const std::string &description() const = 0;

  virtual std::unique_ptr<parameter> copy() const = 0;

  virtual void set_index(unsigned i) {
    throw std::runtime_error("parameter does not respond to set_index.");
  }

  virtual void set_number(double x) {
    throw std::runtime_error("parameter does not respond to set_number.");
  }
};

namespace impl {

template <class T>
class parameter_helper : public parameter {
public:
  const std::string &name() const override {
    return _name;
  }

  const std::string &description() const override {
    return _description;
  }

  static const parameter *default_instance() {
    static T param;
    return &param;
  }

  std::unique_ptr<parameter> copy() const override {
    const T *derived_ptr = static_cast<const T*>(this);
    return std::unique_ptr<parameter>(new T(*derived_ptr));
  }

protected:
  template <class S1, class S2>
  parameter_helper(S1 &&name, S2 &&description) {
    _name = name;
    _description = description;
  }

private:
  static std::string _name, _description;
};

template <class T>
std::string parameter_helper<T>::_name;

template <class T>
std::string parameter_helper<T>::_description;

template<class T>
class switch_parameter : public parameter_helper<T> {
public:
  void set_index(unsigned i) override {
    check_input(i);
    _current = i;
  }

protected:
  template<class S1, class S2>
  switch_parameter(S1 &&name, S2 &&description, unsigned initial,
      std::initializer_list<std::string> list)
          : parameter_helper<T>(name, description), _current(initial) {
    _options = list;
    check_input(initial);
  }

private:
  void check_input(unsigned i) {
    if (i > _options.size())
      throw std::domain_error("switch input not in range");
  }

  unsigned _current;
  static std::vector<std::string> _options;
};

template<class T>
std::vector<std::string> switch_parameter<T>::_options;

template <class T>
class number_parameter : public parameter_helper<T> {
public:
  void set_number(double x) override {
    check_input(x);
    _current = x;
  }

protected:
  template <class S1, class S2>
  number_parameter(S1 &&name, S2 &&description, T initial, T min, T max)
      : parameter_helper<T>(name, description), _current(initial) {
    check_input(initial);
    _min = min;
    _max = max;
  }

private:
  static void check_input(double x) {
    if (x < 0 || x > 1) {
      throw std::domain_error("number imput should be in the range [0, 1]");
    }
  }

  T _current;
  static T _min = 0, _max = 0;
};

}

struct bypass : impl::switch_parameter<bypass> {
  bypass(): switch_parameter<bypass>("bypass", "bypass/on", 0,
      {"bypass", "on"}) {}
};

}

#endif
