namespace s21 {

/**
 * Конструктор по умолчанию
 */
template <typename T>
list<T>::list() : list_.size(0),
list_.head(nullptr), list_.tail(nullptr){};

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
  for (const auto &item : items) push_back(item);
}

/**
 * Конструктор перемещения
 * @param l контейнер, который нужно скопировать
 */
template <typename T>
list<T>::list(list &&l) noexcept : list() {
  *this = l;
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
    while (other.list<T>::empty) {
      list<T>::push_back(other.list<T>::front());
      other.list<T>::pop_front();
    }
  }

  return (*this);
}

/**
 * Дает доступ к первому элементу
 * @return const ссылка на начало списка
 */
template <typename T>
list<T>::const_reference list<T>::front() const {
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
typename list<T>::iterator list<T>::begin() const {
  return list_.head;
}

/**
 * Возвращает итератор на конец
 * @return const ссылка на конец списка
 */
template <typename T>
typename list<T>::iterator list<T>::end() {
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
  return this->list_.size;
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
  if (list_.size > 1) {
    list<T>::Node *node(list_.value, list_.head);
    for (size_type i = 0; i < this->list_.size; ++i) {
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
void vector<T>::clear() noexcept {
  while (!list<T>::empty()) {
    list<T>::pop_front();
  }
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

  ++list_.size;
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
    --list_.size;
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

  ++list_.size;
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
    --list_.size;
  }
}

/**
 * Меняет местами текущий элемент и указанный
 * @param other указатель на другой list
 */
template <typename T>
void list<T>::swap(list &other) {
  std::swap(list_.size, other.list_.size);
  std::swap(list_.head, other.list_.head);
  std::swap(list_.tail, other.list_.tail);
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
    this->list_.size--;
  }
}

/**
 *Удаляет последовательные дубликаты элементов
 */
template <typename T>
void list<T>::unique() {
  if (!this->list<T>::empty())
    for (iterator i = list<T>::begin(), iterator j = i;
         last != list<T>::end() && j.node;) {
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
list<T>::iterator list<T>::insert(list<T>::iterator pos,
                                  list<T>::const_reference value) {
  if (pos == list<T>::begin()) {
    list<T>::push_front(value);
    pos = this->list_.head;
  } else if (pos == list<T>::end()) {
    list<T>::push_back(value);
    pos = this->list_.tail;
  } else {
    list<T>::Node *current = pos.node;
    list<T>::Node *new_node = new list<T>::Node(value);

    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
    this->list_.size++;

    pos = list<T>::iterator(new_node);
  }
  return pos;
}

/**
 * Вставляет новые элементы в контейнер непосредственно перед pos
 * @param pos указатель на позицию
 * @param args переменное число аргументов
 * @return итератор 
 */
template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  for (const auto& arg : {args...}) {
    list<T>::insert(pos, arg);
  }
  return pos;
}

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
ListIterator::iterator &ListIterator::operator++() {
  last_node = node;
  node = node->next;
  return *this;
}

/**
 * Перегрузка оператора ++ для итераторв
 */
ListIterator::iterator ListIterator::operator++(int) {
  iterator it = *this;
  node = node->next;
  return it;
}

/**
 * Перегрузка оператора -- для итераторв
 */
ListIterator::iterator &ListIterator::operator--() {
  if (node == nullptr)
    node = last_node;
  else
    node = node->prev;

  return *this;
}

/**
 * Перегрузка оператора -- для итераторв
 */
ListIterator::iterator ListIterator::operator--(int) {
  iterator it = *this;
  node = node->prev;
  return it;
}

/**
 * Перегрузка оператора == для итераторв
 */
bool ListIterator::operator==(const iterator &other) const {
  return node == other.node;
}

/**
 * Перегрузка оператора != для итераторв
 */
bool ListIterator::operator!=(const iterator &other) const {
  return node != other.node;
}

/**
 * Перегрузка оператора < для итераторв
 */
bool ListIterator::operator<(const iterator &other) const {
  return node < other.node;
}

/**
 * Перегрузка оператора <= для итераторв
 */
bool ListIterator::operator<=(const iterator &other) const {
  return node <= other.node;
}

/**
 * Перегрузка оператора > для итераторв
 */
bool ListIterator::operator>(const iterator &other) const {
  return node > other.node;
}

/**
 * Перегрузка оператора >= для итераторв
 */
bool ListIterator::operator>=(const iterator &other) const {
  return node >= other.node;
}

}  // namespace s21