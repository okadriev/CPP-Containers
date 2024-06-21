namespace s21 {
  
/**
 * Удаляет первый элемент в контейнере
 */
template <typename T1, typename T2>
void queue<T1, T2>::pop() {
  int size = queue<T1, T2>::_Get_container().size();

  for (int i; i < size; i++) {
    if (i == size - 1) queue<T1, T2>::_Get_container().pop_back();
    queue<T1, T2>::_Get_container()[i] = queue<T1, T2>::_Get_container()[i + 1];
  }
}

/**
 * Добавляет элемент в контейнер
 * @param value значение, которое нужно добавить
 */
template <typename T1, typename T2>
void queue<T1, T2>::push(const T1 &value) {
  queue<T1, T2>::_Get_container().push_back(value);
}

/**
 * Указывает на первый элемент в контейнере
 * @return ссылка на последний элемент в контейнере
 */
template <typename T1, typename T2>
const T1 &queue<T1, T2>::front() const {
  return _Get_container().front();
}

/**
 * Указывает на последний элемент в контейнере
 * @return ссылка на последний элемент в контейнере
 */
template <typename T1, typename T2>
const T1 &queue<T1, T2>::back() const {
  return _Get_container().back();
}

/**
 * Проверяет контейнер на пустоту
 * @return true - если контейнер пуст, false - если контейнер не пуст
 */
template <typename T1, typename T2>
bool queue<T1, T2>::empty() const {
  return queue<T1, T2>::_Get_container().empty();
}

/**
 * Возвращает размер контейнера
 * @return размер контейнера
 */
template <typename T1, typename T2>
size_t queue<T1, T2>::size() const {
  return queue<T1, T2>::_Get_container().size();
}

/**
 * Возвращает ссылку на контейнер
 * @return тип контейнера
 */
template <typename T1, typename T2>
T2 &queue<T1, T2>::_Get_container() {
  return *this;  // но это не точно
}

/**
 * Перегрузка оператора =
 * @param other - ссылка на другой объект
 * @return ссылка на текущий объект
 */
template <typename T1, typename T2>
queue<T1, T2> &queue<T1, T2>::operator=(T2 &&other) {
  queue<T1, T2>::_Get_container() = other;
  return *this;
}
}  // namespace s21