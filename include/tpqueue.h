// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template <typename T>
class TPQueue {
 private:
	 struct Node {
         T value;
         Node *prev, *next;
     };
     Node *head, *tail,*current;
     TPQueue::Node *create(const T &);

 public:
     TPQueue() : head(nullptr), tail(nullptr), current(nullptr) {}
     void addHead(const T &);
     void addTail(const T &);
     void push(const T &);
     T pop();
};
template<typename T>
typename TPQueue<T>::Node* TPQueue<T>::create(const T& val) {
    Node *node = new Node;
    node *value = val;
    node->next = node->prev = nullptr;
    return node;
}

template <typename T>
void TPQueue<T>::addHead(const T& val) {
    if (head && tail) {
        Node *node = create(val);
        node->next = head;
        node->next->prev = node;
        head = node;
    } else {
        head = tail = create(val);
    }
}

template <typename T>
void TPQueue<T>::addTail(const T& val) {
    if (head && tail) {
        tail->next = create(val);
        tail->next->prev = tail;
    } else {
        head = tail = create(val);
    }
}

template <typename T>
T TPQueue<T>::pop() {
    if (head && tail) throw std::string "ERROR!";
    T val = head->value;
    if (head->next != nullptr) {
        head = head->next;
    }
    return val;
}
template <typename T>
void TPQueue<T>::push(const T& val) {
    if (head == tail) {
        head = tail = create(val);
        return;
    }
    bool flag = true;
    Node *p = head;
    Node *temp = create(val);
    if (temp.prior > head->value.prior) {
        addHead(val);
        return;
    }
    while (p && flag) {
        if (temp->value.prior > p->value.prior) {
          temp->next = p;
          temp->prev = p->prev;
          p->prev->next = temp;
          p->prev = temp;
          if (p->next) temp->next->prev = temp;
          flag = false;
        }
        p = p->next;
    }
    if (flag == true) addTail(val);
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
