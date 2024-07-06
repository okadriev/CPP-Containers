namespace s21 {
template <typename T, std::size_t N>
inline array<T, N>::array(std::initializer_list<data_type> const &items) {
  for (size_type i = 0; i < N; ++i) data_[i] = items.begin()[i];
}

template <typename T, std::size_t N>
inline array<T, N>::array(const array &other) {
  for (size_type i = 0; i < N; ++i) data_[i] = other.data_[i];
};

template <typename T, std::size_t N>
inline array<T, N>::array(array &&other) noexcept {
  for (size_type i = 0; i < N; ++i) data_[i] = other.data_[i];
};

}  // namespace s21