namespace s21 {
/* default constructor, creates empty vector */
template <typename T>
vector<T>::vector() {
  this->data_ = nullptr;
  this->size_ = this->capacity_ = 0U;
}

/* parameterized constructor, creates the vector of size n */
template <typename T>
vector<T>::vector(size_type n) {
  if (n > this->max_size()) {
    throw std::invalid_argument(
        "Invalid argument: container size exceeds maximum");
  }
  this->data_ = n ? new value_type[n] : nullptr;
  this->size_ = this->capacity_ = n;
}

/* initializer list constructor, creates vector initizialized using
 * std::initializer_list */
template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items) {
  this->data_ = new value_type[items.size()];
  this->size_ = this->capacity_ = items.size();
  std::copy(items.begin(), items.end(), this->data_);
}

/* copy constructor */
template <typename T>
vector<T>::vector(const vector &v) {
  this->data_ = new value_type[v.capacity_];
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  std::copy(v.data_, v.data_ + v.size_, this->data_);
}

/* move constructor */
template <typename T>
vector<T>::vector(vector &&v) noexcept {
  this->data_ = v.data_;
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  v.data_ = nullptr;
  v.size_ = v.capacity_ = 0U;
}

/* destructor */
template <typename T>
vector<T>::~vector() {
  if (this->data_ != nullptr) {
    delete[] this->data_;
    this->data_ = nullptr;
  }
  this->size_ = this->capacity_ = 0U;
}

/* assignment operator overload for moving object */
template <typename T>
vector<T> &vector<T>::operator=(vector &&v) noexcept {
  if (this != &v) {
    delete[] this->data_;

    this->data_ = v.data_;
    this->size_ = v.size_;
    this->capacity_ = v.capacity_;

    delete[] v.data_;
    v.data_ = nullptr;
    v.size_ = v.capacity_ = 0U;
  }

  return (*this);
}

/* access methods */
/* access specified element with bounds checking */
template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (this->data_ == nullptr)
    throw std::out_of_range("Out of range: container is empty");
  if (pos >= this->size_)
    throw std::out_of_range("Out of range: element is outside of container");

  return this->data_[pos];
}

/* access specified element with bounds checking (const) */
template <typename T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const {
  if (this->data_ == nullptr)
    throw std::out_of_range("Out of range: container is empty");
  if (pos >= this->size_)
    throw std::out_of_range("Out of range: element is outside of container");

  return this->data_[pos];
}

/* access specified element */
template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  if (this->data_ == nullptr)
    throw std::out_of_range("Out of range: container is empty");
  if (pos >= this->size_)
    throw std::out_of_range("Out of range: element is outside of container");

  return this->data_[pos];
}

/* access specified element (const) */
template <typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const {
  return this->data_[pos];
}

/* access the first element */
template <typename T>
typename vector<T>::const_reference vector<T>::front() const {
  if (this->empty()) {
    throw std::out_of_range("Out of range: no elements in container");
  }
  return this->data_[0];
}

/* access the last element */
template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
  if (this->empty()) {
    throw std::out_of_range("Out of range: no elements in container");
  }
  return this->data_[this->size_ - 1];
}

/* direct access to the underlying array */
template <typename T>
typename vector<T>::iterator vector<T>::data() noexcept {
  return this->data_;
}

/* iterator methods */
/* returns an iterator to the beginning */
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return this->data_;
}

/* returns an iterator to the beginning (const) */
template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const {
  return this->data_;
}

/* returns an iterator to the end */
template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return this->data_ + this->size_;
}

/* returns an iterator to the end (const) */
template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
  return this->data_ + this->size_;
}

/* capacity methods */
/* checks whether the container is empty */
template <typename T>
bool vector<T>::empty() const {
  return this->size_ == 0U;
}

/* returns the number of elements */
template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return this->size_;
}

/* returns the maximum possible number of elements */
template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

/* allocate storage of size elements and copies current array elements to a
 * newely allocated array */
template <typename T>
void vector<T>::reserve(size_type size) {
  if (size > this->max_size()) {
    throw std::invalid_argument(
        "Invalid argument: container size exceeds maximum");
  }

  if (size > this->capacity_) {
    this->reallocate(size);
  }
}

/* reallocate memory for vector */
template <typename T>
void vector<T>::reallocate(size_type size) {
  iterator temp = new value_type[size];
  std::copy(this->data_, this->data_ + this->size_, temp);

  delete[] this->data_;
  this->data_ = temp;
  this->capacity_ = size;
}

/* returns the number of elements that can be held in currently allocated
 * storage */
template <typename T>
typename vector<T>::size_type vector<T>::capacity() const {
  return this->capacity_;
}

/* reduces memory usage by freeing unused memory */
template <typename T>
void vector<T>::shrink_to_fit() {
  if (this->size_ < this->capacity_) {
    this->reallocate(this->size_);
  }
}

/* modifier methods */
/* clears the contents */
template <typename T>
void vector<T>::clear() noexcept {
  this->size_ = 0U;
}

/* inserts elements into concrete pos and returns the iterator that points to
 * the new element */
template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  if (pos < this->begin() || pos > this->end()) {
    throw std::out_of_range("Out of range: element is outside of container");
  }

  size_type index = pos - this->begin();

  if (this->capacity_ == this->size_) {
    this->reserve(this->capacity_ > 0 ? this->capacity_ * 2 : 1);
  }

  for (size_type i = this->size_; i > index; i--) {
    this->data_[i] = std::move(this->data_[i - 1]);
  }

  this->data_[index] = value;
  ++this->size_;

  return this->begin() + index;
}

/* erases element at pos */
template <typename T>
void vector<T>::erase(iterator pos) {
  if (this->empty()) {
    throw std::out_of_range("Out of range: no elements in container");
  }
  if (pos < this->begin() || pos >= this->end()) {
    throw std::out_of_range("Out of range: element is outside of container");
  }

  for (iterator it = pos; it != this->end() - 1; it++) {
    *it = std::move(*(it + 1));
  }
  --this->size_;
}

/* adds an element to the end */
template <typename T>
void vector<T>::push_back(const_reference value) {
  if (this->capacity_ == this->size_) {
    this->reserve(this->capacity_ > 0 ? this->capacity_ * 2 : 1);
  }
  this->data_[this->size_++] = value;
}

/* removes the last element */
template <typename T>
void vector<T>::pop_back() {
  if (this->empty()) {
    throw std::out_of_range("Out of range: no elements in container");
  }
  --this->size_;
}

/* swaps the contents */
template <typename T>
void vector<T>::swap(vector &other) {
  iterator temp = this->data_;
  size_type size = this->size_;
  size_type capacity = this->capacity_;

  this->data_ = other.data_;
  this->size_ = other.size_;
  this->capacity_ = other.capacity_;

  other.data_ = temp;
  other.size_ = size;
  other.capacity_ = capacity;
}

/* inserts new elements into the container directly before pos */
// template <typename T>
// typename vector<T>::iterator vector<T>::insert_many(const_iterator
// pos,
//                                                             Args &&...args);

/* appends new elements to the end of the container */
// template <typename T>
// void vector<T>::insert_many_back(Args &&...args);
}  // namespace s21