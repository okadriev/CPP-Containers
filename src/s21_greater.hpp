#pragma once

namespace s21 {
template <typename T>
struct greater {
  constexpr bool operator()(const T& lhs, const T& rhs) const {
    return lhs > rhs;
  }
};

}  // namespace s21