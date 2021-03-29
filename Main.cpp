// Main.cpp

#include "DoublyLinkedList.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

template <class T>
void menuLogic(DoublyLinkedList<T> list);

int main(int argc, char** argv) {

  // File stream
  std::fstream fileStream;

  // Type of list
  std::string typeChoice = "";
  std::cout << "Enter list type (i - int, f - float, s - std::string): ";
  std::cin >> typeChoice;

  // Integer List
  if (typeChoice == "i") {

    DoublyLinkedList<int> intList;
    int intValue;

    // Read in the file
    fileStream.open(argv[1], std::ios::in);
   
    if (fileStream.is_open()) {
      fileStream >> intValue;

      while (!fileStream.eof()) {
        intList.insertItem(intValue);
	fileStream >> intValue;
    
      }
    } else {
      std::cout << "Failed to open the input file" << std::endl;
      return 0;

    }


    // Applying menu
    menuLogic(intList);
  
  }

  // Float List
  if (typeChoice == "f") {

    DoublyLinkedList<float> floatList;
    float floatValue;

    // Read in file
    fileStream.open(argv[1], std::ios::in);

    if (fileStream.is_open()) {
      fileStream >> floatValue;

      while (!fileStream.eof()) {
        floatList.insertItem(floatValue);
	fileStream >> floatValue;
    
      }
    } else {
      std::cout << "Failed to open the input file" << std::endl;
      return 0;

    }


    // Applying Menu
    menuLogic(floatList);
 
  }

  // String list
  if (typeChoice == "s") {

    DoublyLinkedList<std::string> stringList;
    std::string stringValue;

    // Read in file
    fileStream.open(argv[1], std::ios::in);

    if (fileStream.is_open()) {
      fileStream >> stringValue;

      while (!fileStream.eof()) {
	stringList.insertItem(stringValue);
	fileStream >> stringValue;
    
      }
    } else {
      std::cout << "Failed to open the input file" << std::endl;
      return 0;

    }

    // Applying menu
    menuLogic(stringList);

  }

}

// Constains the recurring menu that applies to all lists
template <class T>
void menuLogic(DoublyLinkedList<T> list) {


  // Printed menu
  std::cout << "insert (i), delete (d), length(l), print (p), deleteSub (b), mode (m)," << std::endl;
  std::cout << "printReverse (r), swapAlt (s), quit (q)" << std::endl;

  std::string command = "";
  bool commCond = true;

  // Recurring menu loop
  while (commCond) {

    std::cout << "Enter a command: ";
    std::cin >> command;

    if (command == "i") {

      std::cin.ignore();
	
      T item;
      std::cout << "Item to insert: ";
      std::cin >> item;
	
      list.insertItem(item);
	
      list.print();
    }

    if (command == "d") {

      std::cin.ignore();

      T item;
      std::cout << "Item to delete: ";
      std::cin >> item;

      list.deleteItem(item);

      list.print();

    }

    if (command == "l") {
	
      std::cout << "The length is: "  << list.lengthIs() << std::endl;

    }

    if (command == "p") {

      list.print();

    }

    if (command == "b") {

      T lowerBound;
      std::cout << "Enter a lower bound: ";
      std::cin >> lowerBound;

      T upperBound;
      std::cout << "Enter a upper bound: ";
      std::cin >> upperBound;

      std::cout << "Original List: ";
      list.print();

      list.deleteSubsection(lowerBound, upperBound);

      std::cout << "Modified List: ";
      list.print();

    }

    if (command == "m") {

      std::cout << "Mode: " << list.mode() << std::endl;

    }

    if (command == "r") {

      list.printReverse();

    }

    if (command == "s") {

      std::cout << "Original List: ";
      list.print();

      list.swapAlternate();

      std::cout << "Swapped List: ";
      list.print();

    }

    if (command == "q") {

      std::cout << "Quitting program..." << std::endl;
      commCond = false;
      exit(0);

    }

  }

}
