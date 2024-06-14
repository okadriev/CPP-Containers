#include "s21_vector.hpp"

using namespace s21;

/* default constructor, creates empty vector */
template <typename T>
s21_vector<T>::s21_vector() {
  this->size_ = this->capacity_ = 0U;
  this->data_ = nullptr;
}

/* parameterized constructor, creates the vector of size n */
template <typename T>
s21_vector<T>::s21_vector(size_type n) {
  this->size_ = this->capacity_ = n;
  this->data_ = n ? new value_type[n] : nullptr;
}

/* initializer list constructor, creates vector initizialized using
 * std::initializer_list */
template <typename T>
s21_vector<T>::s21_vector(std::initializer_list<value_type> const &items) {
  this->size_ = this->capacity_ = items.size();
  this->data_ = new value_type[items.size()];
  copy(items.begin(), items.end(), this->data_);
}

/* copy constructor */
template <typename T>
s21_vector<T>::s21_vector(const s21_vector &v) {
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  this->data_ = new value_type[v.capacity_];
  copy(v.data_, v.data_ + v.size_, this->data_);
};

/* move constructor */
template <typename T>
s21_vector<T>::s21_vector(s21_vector &&v) noexcept {
  this->size_ = v.size_;
  this->capacity_ = v.capacity_;
  this->data_ = v.data_;
  v.size_ = v.capacity_ = 0;
  v.data_ = nullptr;
}

/* destructor */
template <typename T>
s21_vector<T>::~s21_vector() {
  this->size_ = this->capacity_ = 0;
  delete[] this->data_;
  this->data_ = nullptr;
}

/* assignment operator overload for moving object */
template <typename T>
s21_vector<T> &s21_vector<T>::operator=(s21_vector &&v) noexcept {
  if (this != &v) {
    delete[] this->data_;

    this->size_ = v.size_;
    this->capacity_ = v.capacity_;
    this->data_ = v.data_;

    v.size_ = v.capacity_ = 0;
    delete[] v.data_;
    v.data_ = nullptr;
  }

  return (*this);
}

/* access methods */
/* access specified element with bounds checking */
template <typename T>
reference s21_vector<T>::at(size_type pos) {
  if (pos >= this->size_ || pos < 0) {
    throw out_of_range("Out of range: element is outside of container");
  }
  return this->data_[pos];
}

/* access specified element with bounds checking (const) */
template <typename T>
const_reference s21_vector<T>::at(size_type pos) const {
  if (pos >= this->size_ || pos < 0) {
    throw out_of_range("Out of range: element is outside of container");
  }
  return this->data_[pos];
}

/* access specified element */
template <typename T>
reference s21_vector<T>::operator[](size_type pos) {
  return this->data_[pos];
}

/* access specified element (const) */
template <typename T>
const_reference s21_vector<T>::operator[](size_type pos) const {
  return this->data_[pos];
}

/* access the first element */
template <typename T>
const_reference s21_vector<T>::front() const {
  if (this->size_ == 0) {
    throw out_of_range("Out of range: no elements in container");
  }
  return this->data_[0];
}

/* access the last element */
template <typename T>
const_reference s21_vector<T>::back() const {
  if (this->size_ == 0) {
    throw out_of_range("Out of range: no elements in container");
  }
  return this->data_[this->size_ - 1];
}

/* direct access to the underlying array */
template <typename T>
iterator s21_vector<T>::data() noexcept {
  return this->data_;
}

/* iterator methods */
/* returns an iterator to the beginning */
// template <typename T>
// iterator s21_vector<T>::begin();

/* returns an iterator to the beginning (const) */
// template <typename T>
// const_iterator s21_vector<T>::begin();

/* returns an iterator to the end */
// template <typename T>
// iterator s21_vector<T>::end();

/* returns an iterator to the end (const) */
// template <typename T>
// const_iterator s21_vector<T>::end();

/* capacity methods */
/* checks whether the container is empty */
template <typename T>
bool s21_vector<T>::empty() const {
  return this->size_ == 0;
};

/* returns the number of elements */
template <typename T>
size_type s21_vector<T>::size() const {
  return this->size_;
};

/* returns the maximum possible number of elements */
template <typename T>
size_type s21_vector<T>::max_size() const {
  return numeric_limits<size_type>::max() / sizeof(value_type);
};

/* allocate storage of size elements and copies current array elements to a
 * newely allocated array */
template <typename T>
void s21_vector<T>::reserve(size_type size);

/* returns the number of elements that can be held in currently allocated
 * storage */
template <typename T>
size_type s21_vector<T>::capacity() const;

/* reduces memory usage by freeing unused memory */
template <typename T>
void s21_vector<T>::shrink_to_fit();

/* modifier methods */
/* clears the contents */
template <typename T>
void s21_vector<T>::clear() noexcept : size_(0) {}

/* inserts elements into concrete pos and returns the iterator that points to
 * the new element */
// iterator s21_vector<T>::insert(iterator pos, const_reference value);

/* erases element at pos */
// void s21_vector<T>::erase(iterator pos);

/* adds an element to the end */
// void s21_vector<T>::push_back(const_reference value);

// template <typename T>
// void s21_vector<T>::push_back(T v) {
//   if (m_size == m_capacity) {
//     reserve_more_capacity(m_size * 2);
//   }
//   arr[m_size++] = v;
// }

/* removes the last element */
// void s21_vector<T>::pop_back();

/* swaps the contents */
// void s21_vector<T>::swap(vector &other);

using std::cin, std::cout, std::endl;
// externalizing template instances for correct linking, feel free to find more
// information
template class s21_vector<int>;

int main() {
  s21_vector<int> v = {1, 2, 3, 4, 5};
  v.push_back(6);
  for (int i = 0; i < v.size(); i++) {
    std::cout << v.at(i) << endl;
  }
}