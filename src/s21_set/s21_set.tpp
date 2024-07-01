namespace s21 {

// template <typename value_type>
// set<value_type>::set(std::initializer_list<value_type> const &items) : set()
// {
//   for (const auto &item : items) insert(item);
//   this->m_size_ = items.size();
// };

template <typename value_type>
set<value_type> &set<value_type>::operator=(const set &other) {
  if (this != &other) {
    delete this->tree_;

    this->tree_ = new key_type();
    this->m_size_ = other.m_size_;
    this->tree_->copy_this->tree_(other.tree_);
  }

  return *this;
}

template <typename value_type>
set<value_type> &set<value_type>::operator=(set &&other) noexcept {
  if (this != &other) {
    delete this->tree_;

    this->tree_ = other.tree_;
    this->m_size_ = other.m_size_;
    other.m_size_ = 0;
    other.tree_ = nullptr;
  }

  return *this;
}

template <typename value_type>
void set<value_type>::clear() {
  this->tree_->delete_this->tree_();
  this->m_size_ = 0;
}

template <typename value_type>
pair<typename set<value_type>::iterator, bool> set<value_type>::insert(
    const_reference data) {
  pair<iterator, bool> result;
  result.first = this->this->tree_->insert(data);
  result.second = true;
  (this->this->m_size_)++;

  return result;
}

template <typename value_type>
void set<value_type>::erase(const_reference data) {
  if (contains(data)) {
    this->tree_->remove(data);
    --this->m_size_;
  }
};

template <typename value_type>
void set<value_type>::erase(iterator ptr) {
  if (ptr != end() && contains(*ptr)) {
    this->tree_->remove(*ptr);
    --this->m_size_;
  }
};

template <typename value_type>
void set<value_type>::swap(set &other) {
  std::swap(this->tree_, other.tree_);
  std::swap(this->m_size_, other.m_size_);
}

template <typename value_type>
void set<value_type>::merge(set &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
}

}  // namespace s21