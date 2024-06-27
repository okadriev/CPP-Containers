#ifndef S21_CONTAINERS_H_
#define S21_CONTAINERS_H_

#include "s21_vector/s21_vector.hpp"

namespace s21 {
template <typename T>
class Container {
 public:
  using value_type = T;
  using size_type = std::size_t;

  virtual ~Container() = default;
  virtual size_type size() const = 0;
  virtual bool empty() const = 0;
};
}  // namespace s21

#endif