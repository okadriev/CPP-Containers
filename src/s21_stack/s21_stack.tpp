namespace s21 {

/**
 * Удаляет последний элемент в контейнере
 */
template <typename T1, typename T2>
void stack<T1, T2>::pop() {
  _Get_container().pop_back();
}

/**
 * Добавляет элемент в контейнер
 * @param value значение, которое нужно добавить
 */
template <typename T1, typename T2>
void stack<T1, T2>::push(const T1 &value) {
  _Get_container().push_back(value);
}

/**
 * Указывает на последний элемент в контейнере
 * @return ссылка на последний элемент в контейнере
 */
template <typename T1, typename T2>
const T1 &stack<T1, T2>::top() const {
  return _Get_container().back();
}

/**
 * Проверяет контейнер на пустоту
 * @return true - если контейнер пуст, false - если контейнер не пуст
 */
template <typename T1, typename T2>
bool stack<T1, T2>::empty() const {
  return _Get_container().empty();
}

/**
 * Возвращает размер контейнера
 * @return размер контейнера
 */
template <typename T1, typename T2>
size_t stack<T1, T2>::size() const {
  return _Get_container().size();
}

/**
 * Возвращает ссылку на контейнер
 * @return тип контейнера
 */
template <typename T1, typename T2>
T2 &stack<T1, T2>::_Get_container() {
  return *this;  // но это не точно
}

/**
 * Возвращает const ссылку на контейнер
 * @return тип контейнера
 */
template <typename T1, typename T2>
const T2 &stack<T1, T2>::_Get_container() const {
  return *this;  // но это не точно
}

/**
 * Перегрузка оператора =
 * @param other - ссылка на другой объект
 * @return ссылка на текущий объект
 */
template <typename T1, typename T2>
stack<T1, T2> &stack<T1, T2>::operator=(T2 &&other) {
  _Get_container() = other;
  return *this;
}
}  // namespace s21