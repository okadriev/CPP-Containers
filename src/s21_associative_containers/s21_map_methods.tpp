// #include "s21_map.hpp"

namespace s21 {

template <typename T1, typename T2>
void map<T1, T2>::erase(const key_type &key) {
  this->tree_->remove({key, data_type()});
  this->m_size_--;
}

template <class T1, class T2>
void map<T1, T2>::clear() {
  while (begin() != end()) {
    erase((*begin()).first);
  }
}

template <typename T1, typename T2>
pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert(
    value_type &&value) {
  bool result = false;
  if (!contains(value.first)) {
    this->tree_->insert(value);
    result = true;
    this->m_size_++;
  }
  return {find(value.first), result};
}

template <typename T1, typename T2>
pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert(
    const value_type &value) {
  value_type rvalue(value);
  return insert(std::move(rvalue));
}

template <typename T1, typename T2>
void map<T1, T2>::insert(std::initializer_list<value_type> items) {
  for (const auto &item : items) insert(item);
}

template <class T1, class T2>
void map<T1, T2>::merge(map &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
}

template <typename T1, typename T2>
bool map<T1, T2>::contains(const key_type &key) {
  return find(key) != end();
}

template <typename T1, typename T2>
typename map<T1, T2>::iterator map<T1, T2>::find(const key_type &key) {
  value_type data(key, data_type());
  return iterator(this->tree_->search(data));
}

template <typename T1, typename T2>
std::size_t map<T1, T2>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}

template <typename T1, typename T2>
typename map<T1, T2>::iterator map<T1, T2>::begin() const {
  return iterator(this->tree_->min());
}

template <typename T1, typename T2>
typename map<T1, T2>::iterator map<T1, T2>::end() const {
  return iterator(nullptr);
}

template <class T1, class T2>
std::size_t map<T1, T2>::size() const {
  return this->m_size_;
}

template <class T1, class T2>
bool map<T1, T2>::empty() const {
  return this->tree_->empty();
};

template <class T1, class T2>
void map<T1, T2>::swap(map &other) noexcept {
  std::swap(this->tree_, other.tree_);
  std::swap(this->m_size_, other.m_size_);
}

template <typename T1, typename T2>
map<T1, T2> &map<T1, T2>::operator=(map &&other) noexcept {
  if (this != &other) {
    delete this->tree_;

    this->tree_ = other.tree_;
    this->m_size_ = other.m_size_;
    other.m_size_ = 0;
    other.tree_ = nullptr;
  }

  return *this;
}

}  // namespace s21
