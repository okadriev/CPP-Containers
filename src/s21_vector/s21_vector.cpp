#include "s21_vector.hpp"

using namespace s21;

/* default constructor, creates empty vector */
template <typename T>
s21_vector<T>::s21_vector() {
  this->data_ = nullptr;
  this->size_ = this->capacity_ = 0U;
}

/* parameterized constructor, creates the vector of size n */
template <typename T>
s21_vector<T>::s21_vector(size_type n) {
  if (n > this->max_size()) {
    throw invalid_argument("Invalid argument: container size exceeds maximum");
  }
  this->data_ = n ? new value_type[n] : nullptr;
  this->size_ = this->capacity_ = n;
}

/* initializer list constructor, creates vector initizialized using
 * std::initializer_list */
template <typename T>
s21_vector<T>::s21_vector(initializer_list<value_type> const &items) {
  this->data_ = new value_type[items.size()];
  this->size_ = this->capacity_ = items.size();
  copy(items.begin(), items.end(), this->data_);
}

/* copy constructor */
template <typename T>
s21_vector<T>::s21_vector(const s21_vector &v) {
  this->data_ = new value_type[v.capacity_];
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  copy(v.data_, v.data_ + v.size_, this->data_);
};

/* move constructor */
template <typename T>
s21_vector<T>::s21_vector(s21_vector &&v) noexcept {
  this->data_ = v.data_;
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  v.data_ = nullptr;
  v.size_ = v.capacity_ = 0U;
}

/* destructor */
template <typename T>
s21_vector<T>::~s21_vector() {
  if (this->data_ != nullptr) {
    delete[] this->data_;
  }
  this->data_ = nullptr;
  this->size_ = this->capacity_ = 0U;
}

/* assignment operator overload for moving object */
template <typename T>
s21_vector<T> &s21_vector<T>::operator=(s21_vector &&v) noexcept {
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
typename s21_vector<T>::reference s21_vector<T>::at(size_type pos) {
  if (this->data_ == nullptr)
    throw out_of_range("Out of range: container is empty");
  if (pos >= this->size_)
    throw out_of_range("Out of range: element is outside of container");

  return this->data_[pos];
}

/* access specified element with bounds checking (const) */
template <typename T>
typename s21_vector<T>::const_reference s21_vector<T>::at(size_type pos) const {
  if (this->data_ == nullptr)
    throw out_of_range("Out of range: container is empty");
  if (pos >= this->size_)
    throw out_of_range("Out of range: element is outside of container");

  return this->data_[pos];
}

/* access specified element */
template <typename T>
typename s21_vector<T>::reference s21_vector<T>::operator[](size_type pos) {
  if (this->data_ == nullptr)
    throw out_of_range("Out of range: container is empty");
  if (pos >= this->size_)
    throw out_of_range("Out of range: element is outside of container");

  return this->data_[pos];
}

/* access specified element (const) */
template <typename T>
typename s21_vector<T>::const_reference s21_vector<T>::operator[](
    size_type pos) const {
  return this->data_[pos];
}

/* access the first element */
template <typename T>
typename s21_vector<T>::const_reference s21_vector<T>::front() const {
  if (this->size_ == 0) {
    throw out_of_range("Out of range: no elements in container");
  }
  return this->data_[0];
}

/* access the last element */
template <typename T>
typename s21_vector<T>::const_reference s21_vector<T>::back() const {
  if (this->size_ == 0) {
    throw out_of_range("Out of range: no elements in container");
  }
  return this->data_[this->size_ - 1];
}

/* direct access to the underlying array */
template <typename T>
typename s21_vector<T>::iterator s21_vector<T>::data() noexcept {
  return this->data_;
}

/* iterator methods */
/* returns an iterator to the beginning */
template <typename T>
typename s21_vector<T>::iterator s21_vector<T>::begin() {
  return this->data_;
}

/* returns an iterator to the beginning (const) */
template <typename T>
typename s21_vector<T>::const_iterator s21_vector<T>::begin() const {
  return this->data_;
}

/* returns an iterator to the end */
template <typename T>
typename s21_vector<T>::iterator s21_vector<T>::end() {
  return this->data_ + this->size_;
}

/* returns an iterator to the end (const) */
template <typename T>
typename s21_vector<T>::const_iterator s21_vector<T>::end() const {
  return this->data_ + this->size_;
}

/* capacity methods */
/* checks whether the container is empty */
template <typename T>
bool s21_vector<T>::empty() const {
  return this->size_ == 0;
};

/* returns the number of elements */
template <typename T>
typename s21_vector<T>::size_type s21_vector<T>::size() const {
  return this->size_;
};

/* returns the maximum possible number of elements */
template <typename T>
typename s21_vector<T>::size_type s21_vector<T>::max_size() const {
  return numeric_limits<size_type>::max() / sizeof(value_type);
};

/* allocate storage of size elements and copies current array elements to a
 * newely allocated array */
template <typename T>
void s21_vector<T>::reserve(size_type size) {
  if (size > this->max_size()) {
    throw invalid_argument("Invalid argument: container size exceeds maximum");
  }

  if (size > this->capacity_) {
    this->reallocate(size);
  }
}

/* reallocate memory for vector */
template <typename T>
void s21_vector<T>::reallocate(size_type size) {
  iterator temp = new value_type[size];
  copy(this->data_, this->data_ + this->size_, temp);

  delete[] this->data_;
  this->data_ = temp;
  this->capacity_ = size;
}

/* returns the number of elements that can be held in currently allocated
 * storage */
template <typename T>
typename s21_vector<T>::size_type s21_vector<T>::capacity() const {
  return this->capacity_;
}

/* reduces memory usage by freeing unused memory */
template <typename T>
void s21_vector<T>::shrink_to_fit() {
  if (this->size_ < this->capacity_) {
    this->reallocate(this->size_);
  }
}

/* modifier methods */
/* clears the contents */
template <typename T>
void s21_vector<T>::clear() noexcept {
  this->size_ = 0U;
}

/* inserts elements into concrete pos and returns the iterator that points to
 * the new element */
// typename s21_vector<T>::iterator s21_vector<T>::insert(iterator pos,
// const_reference value) {}

/* erases element at pos */
// void s21_vector<T>::erase(iterator pos) {}

/* adds an element to the end */
// void s21_vector<T>::push_back(const_reference value) {}

/* removes the last element */
// void s21_vector<T>::pop_back() {}

/* swaps the contents */
// void s21_vector<T>::swap(s21_vector &other) {}

using std::cin, std::cout, std::endl;

int main() {
  s21_vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  size_t max = v.max_size();
  cout << max << endl;

  //  v.push_back(6);
  //  for (int i = 0; i < v.size(); i++) {
  //    cout << v.at(i) << endl;
  //  }
}