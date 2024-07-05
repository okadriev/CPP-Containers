namespace s21 {
template <typename T1, typename T2>
bool map<T1, T2>::operator==(const map<T1, T2> &other) {
  if (this->m_size_ != other.m_size_) return false;

  bool result = true;

  for (auto it = other.begin(); it != other.end() && result; ++it) {
    auto fonded = find((*it).first);
    result = fonded != this->end() && (*fonded).second == (*it).second;
  }
  return result;
}

template <typename T1, typename T2>
map<T1, T2> &map<T1, T2>::operator=(const map &other) {
  if (this != &other) {
    delete this->tree_;

    this->tree_ = new tree_type();
    this->m_size_ = other.m_size_;
    this->tree_->copy_tree(other.tree_);
  }

  return *this;
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

template <typename key_type, typename data_type>
data_type &map<key_type, data_type>::operator[](const key_type &key) {
  if (!contains(key)) this->insert({key, data_type()});
  return (this->tree_->search({key, data_type()}))->data.second;
}

}  // namespace s21