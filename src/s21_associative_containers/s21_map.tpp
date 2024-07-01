// #include "s21_map.hpp"

namespace s21 {

template <typename T1, typename T2>
void map<T1, T2>::erase(const key_type &key) {
  tree_->remove(tree_->search({key, data_type()}));
  m_size_--;
}

template <typename T1, typename T2>
map<T1, T2>::map(std::initializer_list<value_type> const &items) : map() {
  insert(items);
}

template <class T1, class T2>
void map<T1, T2>::clear() {
  for (auto it = begin(); it != end(); ++it) erase((*it).first);
}

template <typename T1, typename T2>
map<T1, T2>::map(const map<T1, T2> &other)
    : tree_(new tree_type()), m_size_(other.m_size_) {
  tree_->copy_tree(other.tree_);
}

template <typename T1, typename T2>
map<T1, T2>::map(map<T1, T2> &&other) : tree_(other), m_size_(other.m_size_) {
  other.tree_ = nullptr;
  other.m_size_ = 0;
}

template <typename T1, typename T2>
pair<typename map<T1, T2>::iterator, bool> map<T1, T2>::insert(
    value_type &&value) {
  bool result = false;
  if (!contains(value.first)) {
    tree_->insert(value);
    result = true;
    m_size_++;
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
void map<T1, T2>::merge(map &) {}

template <typename T1, typename T2>
bool map<T1, T2>::contains(const key_type &key) {
  return find(key) != end();
}

template <typename T1, typename T2>
typename map<T1, T2>::iterator map<T1, T2>::find(const key_type &key) {
  value_type data(key, data_type());
  return iterator(tree_->search(data));
}

template <typename T1, typename T2>
std::size_t map<T1, T2>::max_size() const {
  return std::numeric_limits<value_type>::max() / sizeof(value_type);
}

template <typename T1, typename T2>
typename map<T1, T2>::iterator map<T1, T2>::begin() const {
  return iterator(tree_->min());
}

template <typename T1, typename T2>
typename map<T1, T2>::iterator map<T1, T2>::end() const {
  return iterator(nullptr);
}

template <class T1, class T2>
std::size_t map<T1, T2>::size() const {
  return m_size_;
}

template <class T1, class T2>
bool map<T1, T2>::empty() const {
  return tree_->empty();
};

template <typename T1, typename T2>
bool map<T1, T2>::operator==(const map<T1, T2> &) {
  return false;
}

template <typename T1, typename T2>
map<T1, T2> &map<T1, T2>::operator=(const map &other) {
  if (this != &other) {
    delete tree_;

    tree_ = new tree_type();
    m_size_ = other.m_size_;
    tree_->copy_tree(other.tree_);
  }

  return *this;
}

template <typename T1, typename T2>
map<T1, T2> &map<T1, T2>::operator=(map &&other) noexcept {
  if (this != &other) {
    delete tree_;

    tree_ = other.tree_;
    m_size_ = other.m_size_;
    other.m_size_ = 0;
    other.tree_ = nullptr;
  }

  return *this;
}

}  // namespace s21
