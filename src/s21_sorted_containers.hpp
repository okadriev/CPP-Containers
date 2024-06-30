#include "s21_containers.hpp"
#include "s21_pair.hpp"

namespace s21 {

template <typename T>
class sorted_container : public container<T> {
 private:
  struct Node {
   private:
    enum e_color { RED, BLACK };

   public:
    T data;
    Node *left, *right, *parent;
    e_color color;

    Node(T data = 0)
        : data(data),
          left(nullptr),
          right(nullptr),
          parent(nullptr),
          color(true) {}
  };

  class rb_tree {
   private:
    using size_t = typename container<T>::size_t;

    Node *root;

    Node *copy_node(Node *node);
    void remove_node(Node *target);
    void delete_tree(Node *);

    void rotate_left(Node *&);
    void rotate_right(Node *&);
    void fix_2_red(Node *&);
    void fix_2_black(Node *&);

    size_t count_elements(Node *node, const T &data) const;
    pair<Node *, Node *> element_range(Node *node, const T &data);
    void print(Node *node, int level) const;  // Дебаг

   public:
    rb_tree() : root(nullptr) {}
    rb_tree(const rb_tree *other) { copy_tree(other); }
    ~rb_tree() { delete_tree(root); }

    void copy_tree(const rb_tree *other);
    Node *insert(const T &data);
    void remove(const T &data);

    Node *min() const;
    Node *search(const T &) const;
    bool empty() const { return (this == nullptr) || (root == nullptr); };
    size_t count(const T &data) const;
    std::pair<Node *, Node *> equal_range(const T &data);
    void print_tree() const { print(root, 0); };  // Дебаг
  };

 public:
  class iterator {
   private:
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Node *node_;

    Node *next_node(Node *node) const;

   public:
    iterator() : node_(nullptr) {};
    iterator(Node *node) : node_(node) {};
    ~iterator() {};

    bool operator==(const iterator &s) const { return (node_ == s.node_); };
    bool operator!=(const iterator &s) const { return (node_ != s.node_); };
    reference operator*() const { return node_->data; };
    iterator &operator++() {
      node_ = next_node(node_);
      return *this;
    };
  };

  virtual void insert(const T &value) = 0;
};

template <typename T>
Node<T> *iterator<T>::next_node(Node *node) const {
  if (node == nullptr) return nullptr;

  Node *next = nullptr;

  if (node->right) {
    next = node->right;
    while (next->left) next = next->left;

  } else {
    next = node->parent;
    while (next && node == next->right) {
      node = next;
      next = next->parent;
    }
  }

  return next;
};

}  // namespace s21

#include "s21_rb_tree.ipp"
