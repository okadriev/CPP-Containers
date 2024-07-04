namespace s21 {

template <typename T1, typename T2>
inline bool pair<T1, T2>::operator==(T1 const key) const noexcept {
  return first == key;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator!=(T1 const key) const noexcept {
  return first != key;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator<(T1 const key) const noexcept {
  return first < key;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator<=(T1 const key) const noexcept {
  return first <= key;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator>=(T1 const key) const noexcept {
  return first >= key;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator>(T1 const key) const noexcept {
  return first > key;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator==(const pair &other) const noexcept {
  return first == other.first && second == other.second;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator!=(const pair &other) const noexcept {
  return first != other.first || second != other.second;
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator<(const pair &other) const noexcept {
  return first < other.first || (first == other.first && second < other.second);
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator<=(const pair &other) const noexcept {
  return first < other.first ||
         (first == other.first && second <= other.second);
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator>=(const pair &other) const noexcept {
  return first > other.first ||
         (first == other.first && second >= other.second);
}

template <typename T1, typename T2>
bool pair<T1, T2>::operator>(const pair &other) const noexcept {
  return first > other.first || (first == other.first && second > other.second);
}

template <typename T1, typename T2>
pair<T1, T2> &pair<T1, T2>::operator=(const pair &other) noexcept {
  if (this != &other) {
    first = other.first;
    second = other.second;
  }
  return *this;
}

template <typename T1, typename T2>
pair<T1, T2> &pair<T1, T2>::operator=(pair &&other) noexcept {
  if (this != &other) {
    first = std::move(other.first);
    second = std::move(other.second);
  }
  return *this;
}

}  // namespace s21