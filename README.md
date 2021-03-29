
Authors:

Shubh Trivedi (811721167), Sourin Paturi (811446274)

Files:

DoublyLinkedList.h
DoublyLinkedList.cpp
Main.cpp
int-input.txt
int-input2.txt
float-input.txt
string-input.txt
README.md

Use “make” to compile and run program.

Delete Subsection: 
First, the code checks where the node is pointing and while this free node isn’t pointing where it needs to be it iterates towards there. Then it goes through and finds which nodes need to be deleted and points the previous head to the new tail.
Time complexity: O(n) because we must traverse the list to find which nodes to delete. This is the most efficient way.

Mode: 
We essentially create a value that we assign as nothing. Then we go through the List and find the maximum recurring number and assign it to the mode to find the value we are seeking.
Time complexity: O(n) because we must traverse the list to find which every node of the same value. This is the most efficient way.

SwapAlt: 
We create a temporary node which holds the value of the next node’s value and then check to see that unless it is pointing to nullptr that these values be swapped.
Time complexity: O(n) because we must traverse the list to find which nodes we can swap. This is the most efficient way.

