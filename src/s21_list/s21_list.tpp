namespace s21 {

template <typename T>
void list<T>::print_list() {
  std::cout << "[ ";
  for (iterator i = list<T>::iterator(begin()); i.node; ++i) {
    std::cout << i.node->value << " ";
  }
  std::cout << "]" << std::endl;
}

/**
 * Конструктор по умолчанию
 */
template <typename T>
list<T>::list() : list_({0, nullptr, nullptr}){};

/**
 * Конструктор с параметром n, создает список
 * @param n размер контейнера
 */
template <typename T>
list<T>::list(size_type n) : list() {
  if (n > this->max_size())
    throw std::invalid_argument(
        "Invalid argument: container size exceeds maximum");

  for (size_type i = 0; i < n; ++i) push_back(T());
}

/**
 * Конструктор списка инициализаторов
 * @param items список инициализаторов
 */
template <typename T>
list<T>::list(std::initializer_list<value_type> const &items) : list() {
  for (const auto &item : items) push_back(item);
}

/**
 * Копирующий конструктор
 * @param l контейнер, который нужно скопировать
 */
template <typename T>
list<T>::list(const list &l) : list() {
  Node *current = l.list_.head;
  while (current) {
    push_back(current->value);
    current = current->next;
  }
}

/**
 * Конструктор перемещения
 * @param l контейнер, который нужно скопировать
 */
template <typename T>
list<T>::list(list &&l) noexcept : list() {
  list_.size = l.list_.size;
  list_.head = l.list_.head;
  list_.tail = l.list_.tail;
  l.list_.size = 0;
  l.list_.head = nullptr;
  l.list_.tail = nullptr;
  std::cout << "left constructor";
  std::cout << list_.head << std::endl;
}

/**
 * Деструктор
 */
template <typename T>
list<T>::~list() {
  list<T>::clear();
}

/**
 * Перегрузка оператора =
 * @param l контейнер, к которому нужно приравнять
 * @return ссылка на текущий объект
 */
template <typename T>
list<T> &list<T>::operator=(list &&other) noexcept {
  if (this != &other) {
    list<T>::clear();
    while (!other.empty()) {
      list<T>::push_back(other.front());
      other.pop_front();
    }
  }

  return (*this);
}

/**
 * Дает доступ к первому элементу
 * @return const ссылка на начало списка
 */
template <typename T>
typename list<T>::const_reference list<T>::front() const {
  if (this->empty())
    throw std::out_of_range("Out of range: no elements in container");

  return list_.head->value;
}

/**
 * Дает доступ к последнему элементу
 * @return const ссылка на конец списка
 */
template <typename T>
typename list<T>::const_reference list<T>::back() const {
  if (this->empty())
    throw std::out_of_range("Out of range: no elements in container");

  return list_.tail->value;
}

/**
 * Возвращает итератор на начало
 * @return const ссылка на начало списка
 */
template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  return list_.head;
}

/**
 * Возвращает итератор на конец
 * @return ссылка на конец списка
 */
template <typename T>
typename list<T>::iterator list<T>::end() {
  return list<T>::iterator(list_.tail);
}

/**
 * Возвращает итератор на начало
 * @return ссылка на начало списка
 */
template <typename T>
typename list<T>::iterator list<T>::begin() {
  return list<T>::iterator(list_.head);
}

/**
 * Возвращает итератор на конец
 * @return const ссылка на конец списка
 */
template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return list_.tail;
}

/**
 * Проверяет контейнер на пустоту
 * @return true - если контейнер пуст, false - если контейнер не пуст
 */
template <typename T>
bool list<T>::empty() const {
  return list_.head == nullptr;
}

/**
 * Возвращает размер контейнера
 * @return размер контейнера
 */
template <typename T>
typename list<T>::size_type list<T>::size() const {
  return this->list_.size_list;
}

/**
 * Возвращает максимально возможное количество элементов
 * @return max размер контейнера
 */
template <typename T>
typename list<T>::size_type list<T>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(list_) / 2;
}

/**
 * Mеняет порядок элементов на противоположный
 */
template <typename T>
void list<T>::reverse() {
  if (list_.size_list > 1) {
    list<T>::Node *node = this->list_.head;;
    for (size_type i = 0; i < this->list_.size_list; ++i) {
      std::swap(node->prev, node->next);
      node = node->next;
    }
    std::swap(this->list_.head, this->list_.tail);
  }
}

/**
 * Очищает содержимое
 */
template <typename T>
void list<T>::clear() noexcept {
  while (!list<T>::empty()) list<T>::pop_front();
}

/**
 * Добавляет элемент в заголовок
 * @param value значение элемента
 */
template <typename T>
void list<T>::push_front(list<T>::const_reference value) {
  Node *node = new Node(value);
  node->next = list_.head;
  node->prev = nullptr;

  if (list_.head) list_.head->prev = node;
  list_.head = node;
  if (list_.tail == nullptr) list_.tail = node;

  ++list_.size_list;
}

/**
 * Удаляет элемент из начала
 */
template <typename T>
void list<T>::pop_front() {
  if (list_.head) {
    Node *node = list_.head;
    list_.head = list_.head->next;

    if (list_.head)
      list_.head->prev = nullptr;
    else
      list_.tail = nullptr;

    delete node;
    --list_.size_list;
  }
}

/**
 * Добавляет элемент в конец
 * @param value значение элемента
 */
template <typename T>
void list<T>::push_back(list<T>::const_reference value) {
  Node *node = new Node(value);
  node->prev = list_.tail;
  node->next = nullptr;

  if (list_.tail) list_.tail->next = node;
  list_.tail = node;
  if (!list_.head) list_.head = node;

  ++list_.size_list;
}

/**
 * Удаляет элемент из конца
 */
template <typename T>
void list<T>::pop_back() {
  if (list_.tail) {
    Node *node = list_.tail;
    list_.tail = list_.tail->prev;

    if (list_.tail)
      list_.tail->next = nullptr;
    else
      list_.head = nullptr;

    delete node;
    --list_.size_list;
  }
}

/**
 * Меняет местами текущий элемент и указанный
 * @param other указатель на другой list
 */
template <typename T>
void list<T>::swap(list &other) {
  std::swap(list_.size_list, other.list_.size_list);
  std::swap(list_.head, other.list_.head);
  std::swap(list_.tail, other.list_.tail);
}

/**
 * Сортивка списка
 */
template <typename T>
void list<T>::sort() {
  std::cout << "list.sort: " << front() << ' ' << back() << std::endl;

  this->list_.head = MergeSort(this->list_.head);
  this->list_.tail = this->list_.head;
  while (this->list_.tail->next) {
    this->list_.tail = this->list_.tail->next;
  }

  std::cout << "list.sort: " << front() << ' ' << back() << std::endl;
}

template <typename T>
typename list<T>::Node *list<T>::MergeSort(typename list<T>::Node *head) {
  int flag = 0;
  typename list<T>::Node *left = nullptr;
  typename list<T>::Node *right = nullptr;

  if (head && head->next) {
    flag = 1;
    typename list<T>::Node *node1 = head;
    typename list<T>::Node *node2 = head;

    while (node2->next && node2->next->next) {
      node1 = node1->next;
      node2 = node2->next->next;
    }

    typename list<T>::Node *middle = node1;
    typename list<T>::Node *next_middle = middle->next;
    middle->next = nullptr;

    left = MergeSort(head);
    right = MergeSort(next_middle);
  }

  return flag ? Merge(left, right) : head;
}

template <typename T>
typename list<T>::Node *list<T>::Merge(typename list<T>::Node *left,
                                       typename list<T>::Node *right) {
  typename list<T>::Node *result = nullptr;
  if (left && right) {
    if (left->value <= right->value) {
      result = left;
      result->next = Merge(left->next, right);
    } else {
      result = right;
      result->next = Merge(left, right->next);
    }
  }
  return !left ? right : !right ? left : result;
}

/**
 * Oбъединяет два отсортированных списка
 * @param pos указатель на позицию
 * @param other указатель на другой list
 */
template <typename T>
void list<T>::merge(list<T> &other) {
  list<T>::sort();
  other.list<T>::sort();
  list<T>::insert_many(list<T>::end(), other);
}

/**
 * Переносит элементы из списка other, начиная с позиции
 * @param pos указатель на позицию
 * @param other указатель на другой list
 */
template <typename T>
void list<T>::splice(list<T>::const_iterator pos, list<T> &other) {
  list<T>::insert_many(pos, other);
}

/**
 * Стирает элемент в позиции
 * @param pos указатель на позицию
 */
template <typename T>
void list<T>::erase(iterator pos) {
  if (pos == begin()) {
    list<T>::pop_front();
  } else if (pos.node == this->list_.tail) {
    list<T>::pop_back();
  } else {
    list<T>::Node *node = pos.node;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete[] node;
    this->list_.size_list--;
  }
}

/**
 *Удаляет последовательные дубликаты элементов
 */
template <typename T>
void list<T>::unique() {
  if (!this->list<T>::empty())
    for (iterator i = list<T>::begin(), j = i; i != list<T>::end() && j.node;) {
      j = i;
      ++j;
      if (*i == *j)
        list<T>::erase(j);
      else
        ++i;
    }
}

/**
 * Вставляет элемент в конкретную позицию и возвращает итератор, указывающий на
 * новый элемент
 * @param pos указатель на позицию
 * @param value значение элемента
 * @return итератор на новый элемент
 */
template <typename T>
typename list<T>::iterator list<T>::insert(list<T>::iterator pos,
                                           list<T>::const_reference value) {
  if (pos == list<T>::begin()) {
    list<T>::push_front(value);
    pos = list<T>::iterator(this->list_.head);
  } else if (pos == list<T>::end()) {
    list<T>::push_back(value);
    pos = list<T>::iterator(this->list_.tail);
  } else {
    Node *new_node = new Node(value);
    Node *prev_node = list_.head;
    for (iterator it = list<T>::begin(); it != pos; ++it) {
      prev_node = prev_node->next;
    }
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next->prev = new_node;
    prev_node->next = new_node;
    ++list_.size_list;

    pos = list<T>::iterator(new_node);
  }
  return pos;
}

// template <typename T>
// void list<T>::insert_(list<T>::const_iterator pos,
//                                            list<T>::const_reference value) {
//   if (pos == list<T>::begin()) {
//     list<T>::push_front(value);
//     // pos = list<T>::iterator(this->list_.head);
//   } else if (pos == list<T>::end()) {
//     list<T>::push_back(value);
//     // pos = list<T>::iterator(this->list_.tail);
//   } else {
//     Node *new_node = new Node(value);
//     Node *prev_node = list_.head;
//     for (iterator it = list<T>::begin(); it != pos; ++it) {
//       prev_node = prev_node->next;
//     }
//     new_node->next = prev_node->next;
//     new_node->prev = prev_node;
//     prev_node->next->prev = new_node;
//     prev_node->next = new_node;
//     ++list_.size_list;

//     // pos = list<T>::iterator(new_node);
//   }
// }

/**
 * Вставляет новые элементы в контейнер непосредственно перед pos
 * @param pos указатель на позицию
 * @param args переменное число аргументов
 * @return итератор
 */
// template <typename T>
// template <typename... Args>
// typename list<T>::iterator list<T>::insert_many(const_iterator pos,
//                                                 Args &&...args) {

//     for (const auto& arg : {args...}) {
//     insert(pos, arg);
//   }
  
//   return pos;
// }

/**
 * Добавляет новые элементы в верхнюю часть контейнера
 * @param pos указатель на позицию
 * @param args переменное число аргументов
 * @return итератор
 */
template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  list<T>::insert_many(list<T>::begin(), std::forward<Args>(args)...);
}

/**
 * Добавляет новые элементы в конец контейнера
 * @param pos указатель на позицию
 * @param args переменное число аргументов
 * @return итератор
 */
template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  list<T>::insert_many(list<T>::end(), std::forward<Args>(args)...);
}

/**
 * Перегрузка оператора ++ для итераторв
 */
template <typename T>
typename list<T>::ListIterator::iterator &list<T>::ListIterator::operator++() {
  last_node = node;
  node = node->next;
  return *this;
}

/**
 * Перегрузка оператора ++ для итераторв
 */
template <typename T>
typename list<T>::ListIterator::iterator list<T>::ListIterator::operator++(
    int) {
  iterator i = *this;
  node = node->next;
  return i;
}

/**
 * Перегрузка оператора -- для итераторв
 */
template <typename T>
typename list<T>::ListIterator::iterator &list<T>::ListIterator::operator--() {
  if (node == nullptr)
    node = last_node;
  else
    node = node->prev;

  return *this;
}

/**
 * Перегрузка оператора -- для итераторв
 */
template <typename T>
typename list<T>::ListIterator::iterator list<T>::ListIterator::operator--(
    int) {
  iterator i = *this;
  node = node->prev;
  return i;
}

/**
 * Перегрузка оператора == для итераторв
 */
template <typename T>
bool list<T>::ListIterator::operator==(const iterator &other) const {
  return node == other.node;
}

/**
 * Перегрузка оператора != для итераторв
 */
template <typename T>
bool list<T>::ListIterator::operator!=(const iterator &other) const {
  return node != other.node;
}

/**
 * Перегрузка оператора < для итераторв
 */
template <typename T>
bool list<T>::ListIterator::operator<(const iterator &other) const {
  return node < other.node;
}

/**
 * Перегрузка оператора <= для итераторв
 */
template <typename T>
bool list<T>::ListIterator::operator<=(const iterator &other) const {
  return node <= other.node;
}

/**
 * Перегрузка оператора > для итераторв
 */
template <typename T>
bool list<T>::ListIterator::operator>(const iterator &other) const {
  return node > other.node;
}

/**
 * Перегрузка оператора >= для итераторв
 */
template <typename T>
bool list<T>::ListIterator::operator>=(const iterator &other) const {
  return node >= other.node;
}

template <typename T>
typename list<T>::value_type *list<T>::ListIterator::operator->() const {
  return &node->value;
}

template <typename T>
typename list<T>::reference list<T>::ListIterator::operator*() const {
  return node->value;
}

}  // namespace s21