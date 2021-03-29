// DoublyLinkedList.cpp

#include "DoublyLinkedList.h"

#include <iostream>
#include <string>

// Constructors and Destructors
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {

  this->head = nullptr;
  this->tail = nullptr;

}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {

  NodeType<T> *currNode = nullptr;

  while(this->head == nullptr && this->tail != nullptr) {
    currNode = head;
    head = head->next;
    delete currNode;
  }

  tail = nullptr;

}

// List operations
template <class T>
void DoublyLinkedList<T>::insertItem(T &item) {

  NodeType<T> *tempNode = new NodeType <T>;

  tempNode->data = item;
  tempNode->next = nullptr;
  tempNode->back = nullptr;

  // Empty list case
  if (head == nullptr) {
    
    head = tempNode;
    tail = tempNode;
    return;
    
  }

  if (item < head->data) {
    
    tempNode->next = head;
    head->back = tempNode;
    head = tempNode;
    return;
    
  }

  if (item > tail-> data) {

    tail->next = tempNode;
    tempNode->back = tail;
    tail = tempNode;
    return;

  }

  NodeType<T> *freeNode = head;

  while (freeNode != nullptr && freeNode->data < item) {
    freeNode = freeNode->next;

  }

  NodeType<T> *prevNode = freeNode->back;
  prevNode->next = tempNode;
  tempNode->back = prevNode;
  tempNode->next = freeNode;
  freeNode-> back = tempNode;

}

template <class T>
void DoublyLinkedList<T>::deleteItem(T &item) {

  NodeType<T> *tempNode = head;

  while (tempNode != nullptr) {
    if (tempNode->data == item) {
      break;
    }

    tempNode = tempNode->next;
  }

  // Empty List case
  if (head == nullptr) {
    std::cout << "You cannot delete from an empty list" << std::endl;
  }
  
  if (tempNode != nullptr) {

    if (tempNode->next == nullptr && tempNode->back == nullptr) {
      
      delete tempNode;
      head = nullptr;
      tail = nullptr;


    } else if (tempNode->back == nullptr) {
      
      head = head->next;
      head->back = nullptr;
      delete tempNode;


    } else if (tempNode->next == nullptr) {

      tail = tail->back;
      tail->next = nullptr;
      delete tempNode;

    } else {

      
      NodeType<T> *prevNode;
      NodeType<T> *freeNode;

      prevNode = tempNode->back;
      freeNode = tempNode->next;
      prevNode->next = freeNode;
      freeNode->back = prevNode;

      delete tempNode;      
    
    }

  } else {
    std::cout << "Item not in list" << std::endl;
  }

}

template <class T>
int DoublyLinkedList<T>::lengthIs() const {

  int length = 0;
  NodeType<T> *tempNode = head;

  while (tempNode != nullptr) {
      length++;
      tempNode = tempNode->next;
      
    }
  return length;
}

template <class T>
void DoublyLinkedList<T>::print() {

  // Empty list case
  if (head == nullptr) {

    std::cout << "List is empty" << std::endl;

  } else {

    NodeType<T> *tempNode = head;
    while(tempNode != nullptr) {
      std::cout << tempNode->data<<" ";
      tempNode = tempNode->next;
    }
    
    std::cout << std::endl;
  }
  

}

template <class T>
void DoublyLinkedList<T>::printReverse() {

  NodeType<T> *currNode = tail;

  while (currNode != nullptr) {
    std::cout << currNode->data << " ";

    currNode = currNode->back;
  }

  std::cout << std::endl;
  

}

// Special functions
template <class T>
void DoublyLinkedList<T>::deleteSubsection(T &lower, T &upper) {

  NodeType<T> *freeNode;

  // Empty list case
  if (head == nullptr) {
    return;

  }

  if (head->data > upper) {
    return;

  }

  if (tail->data < lower) {
    return;

  }

  freeNode = head;

  while (freeNode != nullptr && freeNode->data < lower) {

    freeNode = freeNode->next;
    
  }

  if (freeNode != nullptr) {

    if (freeNode->next == nullptr) {

      tail = tail->back;
      tail->next = nullptr;

      delete freeNode;
      return;
      
    }

    if (freeNode->back == nullptr) {

      head = head->next;
      head->back = nullptr;

      delete freeNode;

      deleteSubsection(lower, upper);
      return;
      
    }

    if (freeNode->next == nullptr && freeNode->back == nullptr) {

      head = nullptr;
      tail = nullptr;

      delete freeNode;

      return;

    } else {

      NodeType<T> *prevNode = tail;

      while (prevNode != nullptr && prevNode->data > upper) {

	prevNode = prevNode->back;
	
      }

      if (prevNode->next == freeNode) {

	return;
	
      } else {

	freeNode->back->next = prevNode->next;
	if (prevNode->next != nullptr) {
	  prevNode->next->back = freeNode->back;
	  
	}

	NodeType<T> *tempNode;

	while (freeNode != prevNode) {
	  tempNode = freeNode;
	  freeNode = freeNode->next;

	  delete tempNode;
	  
	}

	delete freeNode;
	
      }
      return;

    }

  }

}

template <class T>
T DoublyLinkedList<T>::mode() {

  T mode = 0;
  int m = 0;
  int f = 0;

  if (head == nullptr) {
    return mode;
  }

  NodeType<T> *tempNode = head->next;
  mode = head->data;

  T prevElem = head->data;
  m = 1;
  f = 1;

  while(tempNode != nullptr) {

    if (tempNode->data == tempNode->back->data) {
      f++;
      
    } else {

      if (f > m) {
	m = f;
	f = 1;
	mode = prevElem;

      }
    }

    prevElem = tempNode->data;
    tempNode = tempNode->next;
    
  }

  return mode;
}

template <class T>
void DoublyLinkedList<T>::swapAlternate() {

  if (head == nullptr || head == tail) {
    return;
  }

  NodeType<T> *currNode = head;
  NodeType<T> *prevNode = nullptr;

  while (currNode != nullptr && currNode->next != nullptr) {

    NodeType<T> *tempNode = currNode->next;
    currNode->next = tempNode->next;

    if (tempNode->next != nullptr) {
      tempNode->next->back = currNode;
    }

    tempNode->next = currNode;
    currNode->back = tempNode;

    if (prevNode == nullptr) {

      head = tempNode;
      tempNode->back = nullptr;

    } else {

      prevNode->next = tempNode;
      tempNode->back = prevNode;
    }

    prevNode = currNode;
    currNode = currNode->next;
    
  }

  if (currNode == nullptr) {
    tail = prevNode;

  }
}

// Template variations
template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
