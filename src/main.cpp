#include <iostream>

template <typename T>
struct Node {
  T data;
  Node<T> *parent;
  Node<T> *left;
  Node<T> *right;
  bool is_red;

  Node(T data)
      : data(data),
        parent(nullptr),
        left(nullptr),
        right(nullptr),
        is_red(true) {}
};

template <typename T>
class RedBlackTree {
 private:
  Node<T> *root;

  void rotateLeft(Node<T> *&);
  void rotateRight(Node<T> *&);
  void fixViolation(Node<T> *&);
  void fixDoubleBlack(Node<T> *&);
  void inorderHelper(Node<T> *) const;
  void preorderHelper(Node<T> *) const;
  void postorderHelper(Node<T> *) const;
  Node<T> *minValueNode(Node<T> *) const;
  Node<T> *maxValueNode(Node<T> *) const;
  void deleteTree(Node<T> *);

 public:
  RedBlackTree() : root(nullptr) {}
  ~RedBlackTree() { deleteTree(root); }

  void insert(const T &);
  void remove(const T &);
  void inorder() const;
  void preorder() const;
  void postorder() const;
  Node<T> *search(const T &) const;
};

template <typename T>
void RedBlackTree<T>::rotateLeft(Node<T> *&node) {
  Node<T> *rightChild = node->right;
  node->right = rightChild->left;

  if (node->right != nullptr) node->right->parent = node;

  rightChild->parent = node->parent;

  if (node->parent == nullptr)
    root = rightChild;
  else if (node == node->parent->left)
    node->parent->left = rightChild;
  else
    node->parent->right = rightChild;

  rightChild->left = node;
  node->parent = rightChild;
}

template <typename T>
void RedBlackTree<T>::rotateRight(Node<T> *&node) {
  Node<T> *leftChild = node->left;
  node->left = leftChild->right;

  if (node->left != nullptr) node->left->parent = node;

  leftChild->parent = node->parent;

  if (node->parent == nullptr)
    root = leftChild;
  else if (node == node->parent->left)
    node->parent->left = leftChild;
  else
    node->parent->right = leftChild;

  leftChild->right = node;
  node->parent = leftChild;
}

template <typename T>
void RedBlackTree<T>::fixViolation(Node<T> *&node) {
  Node<T> *parent = nullptr;
  Node<T> *grandParent = nullptr;

  while ((node != root) && (node->is_red) && (node->parent->is_red)) {
    parent = node->parent;
    grandParent = node->parent->parent;

    /*  Case : A
        Parent of node is left child of Grand-parent of node */
    if (parent == grandParent->left) {
      Node<T> *uncle = grandParent->right;

      /* Case : 1
         The uncle of node is also red
         Only Recoloring required */
      if (uncle != nullptr && uncle->is_red) {
        grandParent->is_red = 1;
        parent->is_red = 0;
        uncle->is_red = 0;
        node = grandParent;
      } else {
        /* Case : 2
           Node is right child of its parent
           Left-rotation required */
        if (node == parent->right) {
          rotateLeft(parent);
          node = parent;
          parent = node->parent;
        }

        /* Case : 3
           Node is left child of its parent
           Right-rotation required */
        rotateRight(grandParent);
        std::swap(parent->is_red, grandParent->is_red);
        node = parent;
      }
    } else {
      Node<T> *uncle = grandParent->left;

      /*  Case : 1
          The uncle of node is also red
          Only Recoloring required */
      if ((uncle != nullptr) && (uncle->is_red)) {
        grandParent->is_red = 1;
        parent->is_red = 0;
        uncle->is_red = 0;
        node = grandParent;
      } else {
        /* Case : 2
           Node is left child of its parent
           Right-rotation required */
        if (node == parent->left) {
          rotateRight(parent);
          node = parent;
          parent = node->parent;
        }

        /* Case : 3
           Node is right child of its parent
           Left-rotation required */
        rotateLeft(grandParent);
        std::swap(parent->is_red, grandParent->is_red);
        node = parent;
      }
    }
  }

  root->is_red = 0;
}

template <typename T>
void RedBlackTree<T>::insert(const T &data) {
  Node<T> *newNode = new Node<T>(data);
  Node<T> *current = root;
  Node<T> *parent = nullptr;

  while (current != nullptr) {
    parent = current;
    if (data < current->data)
      current = current->left;
    else
      current = current->right;
  }

  // Присваиваем родителя новому узлу
  newNode->parent = parent;

  // Вставляем новый узел в дерево
  if (parent == nullptr) {
    root = newNode;
  } else if (data < parent->data) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }

  fixViolation(newNode);
}

template <typename T>
void RedBlackTree<T>::fixDoubleBlack(Node<T> *&node) {
  if (node == root) return;

  Node<T> *sibling = nullptr;
  Node<T> *parent = nullptr;
  bool leftChild = false;
  if (node != nullptr) {
    parent = node->parent;
    leftChild = (node == parent->left);
  }

  if (leftChild)
    sibling = parent->right;
  else
    sibling = parent->left;

  if (sibling == nullptr)
    fixDoubleBlack(parent);
  else {
    if (sibling->is_red) {
      parent->is_red = 1;
      sibling->is_red = 0;
      if (leftChild)
        rotateLeft(parent);
      else
        rotateRight(parent);
      fixDoubleBlack(node);
    } else {
      if ((sibling->left != nullptr && sibling->left->is_red) ||
          (sibling->right != nullptr && sibling->right->is_red)) {
        if (sibling->left != nullptr && sibling->left->is_red) {
          if (leftChild) {
            sibling->left->is_red = sibling->is_red;
            sibling->is_red = parent->is_red;
            rotateRight(parent);
          } else {
            sibling->left->is_red = parent->is_red;
            rotateRight(sibling);
            rotateLeft(parent);
          }
        } else {
          if (leftChild) {
            sibling->right->is_red = parent->is_red;
            rotateLeft(sibling);
            rotateRight(parent);
          } else {
            sibling->right->is_red = sibling->is_red;
            sibling->is_red = parent->is_red;
            rotateLeft(parent);
          }
        }
        parent->is_red = 0;
      } else {
        sibling->is_red = 1;
        if (!parent->is_red)
          fixDoubleBlack(parent);
        else
          parent->is_red = 0;
      }
    }
  }
}

template <typename T>
void RedBlackTree<T>::remove(const T &data) {
  if (root == nullptr) return;

  Node<T> *v = search(data);

  if (v == nullptr) return;

  Node<T> *u = nullptr;
  if (v->left == nullptr || v->right == nullptr)
    u = v;
  else {
    u = v->right;
    while (u->left != nullptr) u = u->left;
  }

  Node<T> *uParent = u->parent;
  Node<T> *vParent = v->parent;

  bool uvBlack = ((u == nullptr || !u->is_red) && (!v->is_red));

  Node<T> *parent = nullptr;

  if (u == v) {
    if (vParent == nullptr)
      root = nullptr;
    else {
      if (u == uParent->left)
        uParent->left = nullptr;
      else
        uParent->right = nullptr;
    }
    delete u;
    if (u != nullptr) {
      u = nullptr;
    }
    if (uvBlack) fixDoubleBlack(uParent);
    return;
  }

  if (u == nullptr) {
    if (v == root) {
      root = nullptr;
    } else {
      if (uvBlack)
        fixDoubleBlack(v);
      else if (v->is_red)
        v->is_red = 0;
      if (vParent != nullptr) {
        if (v == vParent->left)
          vParent->left = nullptr;
        else
          vParent->right = nullptr;
      }
    }
    delete v;
    return;
  }

  if (u->left != nullptr || u->right != nullptr) {
    if (uParent == nullptr) {
      root = nullptr;
      delete u;
      return;
    }

    if (uParent != nullptr) {
      if (u == uParent->left)
        uParent->left = nullptr;
      else
        uParent->right = nullptr;
    }

    if (uParent != nullptr) {
      parent = uParent;
    }

    if (vParent != nullptr) {
      if (v == vParent->left)
        vParent->left = u;
      else
        vParent->right = u;
    }

    u->parent = vParent;

    if (v == root) root = u;

    if (!v->is_red) {
      if (u->is_red)
        u->is_red = 0;
      else
        fixDoubleBlack(u);
    } else
      u->is_red = 0;

    delete v;
    return;
  }

  if (!u->is_red) {
    if (!u->is_red)
      fixDoubleBlack(u);
    else
      u->is_red = 0;
  }

  if (uParent == nullptr) {
    root = nullptr;
  } else {
    if (uParent->left == u)
      uParent->left = nullptr;
    else
      uParent->right = nullptr;
  }

  delete u;
}

template <typename T>
void RedBlackTree<T>::inorderHelper(Node<T> *node) const {
  if (node == nullptr) return;

  inorderHelper(node->left);
  std::cout << node->data << " ";
  inorderHelper(node->right);
}

template <typename T>
void RedBlackTree<T>::preorderHelper(Node<T> *node) const {
  if (node == nullptr) return;

  std::cout << node->data << " ";
  preorderHelper(node->left);
  preorderHelper(node->right);
}

template <typename T>
void RedBlackTree<T>::postorderHelper(Node<T> *node) const {
  if (node == nullptr) return;

  postorderHelper(node->left);
  postorderHelper(node->right);
  std::cout << node->data << " ";
}

template <typename T>
Node<T> *RedBlackTree<T>::search(const T &data) const {
  Node<T> *temp = root;
  while (temp != nullptr) {
    if (data < temp->data) {
      if (temp->left == nullptr)
        break;
      else
        temp = temp->left;
    } else if (data == temp->data)
      break;
    else {
      if (temp->right == nullptr)
        break;
      else
        temp = temp->right;
    }
  }
  return temp;
}

template <typename T>
void RedBlackTree<T>::inorder() const {
  inorderHelper(root);
}

template <typename T>
void RedBlackTree<T>::preorder() const {
  preorderHelper(root);
}

template <typename T>
void RedBlackTree<T>::postorder() const {
  postorderHelper(root);
}

template <typename T>
Node<T> *RedBlackTree<T>::minValueNode(Node<T> *node) const {
  Node<T> *current = node;
  while (current->left != nullptr) current = current->left;
  return current;
}

template <typename T>
Node<T> *RedBlackTree<T>::maxValueNode(Node<T> *node) const {
  Node<T> *current = node;
  while (current->right != nullptr) current = current->right;
  return current;
}

template <typename T>
void RedBlackTree<T>::deleteTree(Node<T> *node) {
  if (node == nullptr) return;
  deleteTree(node->left);
  deleteTree(node->right);
  delete node;
}

int main() {
  RedBlackTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  std::cout << "Inorder traversal: ";
  tree.inorder();
  std::cout << std::endl;

  std::cout << "Preorder traversal: ";
  tree.preorder();
  std::cout << std::endl;

  std::cout << "Postorder traversal: ";
  tree.postorder();
  std::cout << std::endl;

  std::cout << "Deleting 20\n";
  tree.remove(20);
  std::cout << "Inorder traversal: ";
  tree.inorder();
  std::cout << std::endl;

  return 0;
}