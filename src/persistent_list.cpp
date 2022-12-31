#include <iostream>
#include <persistent_list.hpp>
using namespace std;


template<typename T>
/*!This is a special destructor that avoids a recursive call. */
PersistentList<T>::~PersistentList() {
  Link head = std::move(this->head);
  while (head) {
    /* If we are the last user, we move forward and continue cleaning up the
       list */
    if (head.use_count() == 1)
      head = std::move(head->next);
    else
      break;
  }
}

template<typename T>
T *PersistentList<T>::get_head() {
  if (head)
    return &(head.get()->elem);
  else
    return nullptr;
}

template<typename T>
PersistentList<T> PersistentList<T>::tail() {
  PersistentList<T> tailList;
  if (head) {
    tailList.head = head->next;
  }
  return tailList;
}

template<typename T>
PersistentList<T> PersistentList<T>::prepend(T elem) {
  PersistentList<T> newList;

  /* Create a new node in the front, nad have it point to our
     current head. */
  Link newHead = std::shared_ptr<Node>(new Node);
  newHead->elem = elem;
  newHead->next = this->head;
  newList.head = newHead;
  return newList;
}

// explicit definition: Note, this is kind of bad practice...better to have a the whole thing as a header
template class PersistentList<int>;