#include <stddef.h>

#ifndef NODE
#define NODE

template<class T>
class Node {
private:

public:
  Node();
  Node(T data);
 ~Node();

  T data_;
  Node* left_;
  Node* right_;

};

// Constructor
template<class T>
Node<T>::Node() {
  data_ = NULL;
  left_ = nullptr;
  right_ = nullptr;
}


template<class T>
Node<T>::Node(T data) {
  data_ = data;
  left_ = nullptr;
  right_ = nullptr;
}

// Destructor
template<class T>
Node<T>::~Node() {
}


#endif