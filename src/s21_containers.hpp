#ifndef S21_CONTAINERS_H
#define S21_CONTAINERS_H

namespace s21 {

class Container {
 private:
  /* data */
 public:
  Container();
  ~Container();
};

Container::Container() {}

Container::~Container() {}

class SequenceContainer : public Container {
 public:
  SequenceContainer();
  ~SequenceContainer();

 private:
  /* data */
 public:
  /* methods */
};

}  // namespace s21

#endif  // S21_CONTAINERS_H