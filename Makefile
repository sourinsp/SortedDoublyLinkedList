main: Main.o DoublyLinkedList.o
	g++ -o main Main.o DoublyLinkedList.o

Main.o: DoublyLinkedList.o
	g++ -c -g -Wall -std=c++14 -pedantic-errors Main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -c -g -Wall -std=c++14 -pedantic-errors DoublyLinkedList.cpp

clean:
	rm main.o
	rm DoublyLinkedList.o
	rm main
