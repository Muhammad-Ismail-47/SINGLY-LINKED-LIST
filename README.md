# SINGLY-LINKED-LIST
Singly Linked List code Implemented in C++
# SINGLY-LINKED-LIST

The provided code implements a SinglyLinkedList class in C++. Here's a breakdown of its functionalities:

Node Structure:

Node: This class represents a single node in the linked list. <br>
It has two public members: <br>
data: An integer to store the data value. <br>
next: A pointer to the next node in the list. <br>
It also has a default constructor that initializes data and next to NULL. <br>
A parameterized constructor that takes data as input and initializes data while setting next to NULL. <br>

SinglyLinkedList Class:

SinglyLinkedList: This class represents the entire linked list. <br>
It has two private members: <br>
HEAD: A pointer to the first node in the list. <br>
TAIL: A pointer to the last node in the list (useful for efficient insertions at the end). <br>
It also has a default constructor that initializes HEAD and TAIL to NULL. <br>

Member functions: 

CreateNode(int data): This function creates a new node with the given data and returns a pointer to it.<br>
InsertAtStart(int data): This function inserts a new node with the given data at the beginning of the list. <br>
InsertAtEnd(int data): This function inserts a new node with the given data at the end of the list. <br>
InsertAtSpecificPosition(int data, int position): This function inserts a new node with the given data at a specific position in the list. <br>
DeleteAtStart(): This function deletes the first node from the list. <br>
DeleteAtEnd(): This function deletes the last node from the list. <br>
DeleteAtSpecificPosition(int position): This function deletes a node from a specific position in the list. <br>
PrintList(): This function traverses the list and prints the data of each node. <br>

Main Function:

The main function demonstrates how to use the SinglyLinkedList class. <br>
It creates a linked list object (l1). <br>
It inserts elements at the end, start, and specific positions. <br>
It then demonstrates deleting elements from the start, end, and specific positions. <br>
After each operation, it prints the current state of the list. <br>