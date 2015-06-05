#ifndef PARAMETER_HPP_INCLUDED
#define PARAMETER_HPP_INCLUDED
#include <string>
#include <array>
#include <initializer_list>
#include <stdexcept>

namespace dsb {

struct parameter {
  virtual ~parameter() = default;

  virtual const std::string &name() const = 0;
  virtual const std::string &description() const = 0;

  virtual void set_index(unsigned i);

  virtual void set_number(double x);
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

template<class T, unsigned N>
class switch_parameter : public parameter_helper<T> {
public:
  using type = unsigned;

  void set_index(unsigned i) override {
    check_input(i);
    _current = i;
  }

protected:
  template<class S1, class S2>
  switch_parameter(S1 &&name, S2 &&description, unsigned initial,
      std::initializer_list<std::string> list)
          : parameter_helper<T>(name, description), _current(initial) {
    std::copy(list.begin(), list.end(), _options.begin());
    check_input(initial);
  }

private:
  void check_input(unsigned i) {
    if (i >= _options.size())
      throw std::domain_error("switch input not in range");
  }

  unsigned _current;
  static std::array<std::string, N> _options;
};

template<class T, unsigned N>
std::array<std::string, N> switch_parameter<T, N>::_options;

template <class T>
class number_parameter : public parameter_helper<T> {
public:
  using type = double;

  void set_number(double x) override {
    check_input(x);
    _current = x;
  }

protected:
  template <class S1, class S2>
  number_parameter(S1 &&name, S2 &&description, double initial, double min,
      double max): parameter_helper<T>(name, description), _current(initial) {
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

  double _current;
  static double _min, _max;
};

template<class T>
double number_parameter<T>::_min = 0;

template<class T>
double number_parameter<T>::_max = 0;


}

struct bypass : impl::switch_parameter<bypass, 2> {
  bypass(unsigned initial): switch_parameter<bypass, 2>("bypass", "bypass/on",
      initial, {"bypass", "on"}) {}
};

struct gain : impl::number_parameter<gain> {
  gain(double initial): impl::number_parameter<gain>("gain", "gain(0.0-1.0)",
      initial, 0, 1) {}
};

}

#endif
