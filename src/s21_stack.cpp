#include "s21_stack.hpp"

using namespace s21;
template <typename T1, typename T2>
T2& stack<T1, T2>::_Get_container()
{
    return container_;
}