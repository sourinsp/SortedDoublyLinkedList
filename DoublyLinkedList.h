//  DoubleLinkedList.h

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>


template<class T>
struct NodeType {

  T data;
  NodeType<T> *next;
  NodeType<T> *back;


};

template<class T>
class DoublyLinkedList {

public:

  // Constructors and Destructors
  DoublyLinkedList();

  ~DoublyLinkedList();

  
  // List operations
  void insertItem(T &item);

  void deleteItem(T &item);

  int lengthIs() const;

  void print();

  void printReverse();

  // Special functions
  void deleteSubsection(T &lower, T &upper);

  T mode();

  void swapAlternate();

  
private:

  NodeType<T> *head;
  NodeType<T> *tail;

};

#endif
