#ifndef S21_CONTAINERS_H_
#define S21_CONTAINERS_H_

#include <type_traits>

// #include "s21_queue/s21_queue.hpp"
// #include "s21_stack/s21_stack.hpp"
#include "s21_list/s21_list.hpp"
#include "s21_set/s21_multiset.hpp"
#include "s21_set/s21_set.hpp"
// #include "s21_vector/s21_vector.hpp"

namespace s21 {
template <typename T>
class container {
 public:
  using value_t = T;
  using size_t = std::size_t;

  virtual ~container() = default;
  virtual size_t size() const = 0;
  virtual bool empty() const = 0;
};
}  // namespace s21

#endif