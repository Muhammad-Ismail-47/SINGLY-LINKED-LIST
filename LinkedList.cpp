# include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() : data(NULL), next(NULL) {}	// DEFAULT CONSTRUCTOR TO INITAILIZE NODE

	Node(int data) : data(data), next(NULL) {} 	// PARAMETERIZED CONSTRUCTOR TO INTIALIZE NODE
};

class SinglyLinkedList {
	Node* HEAD;
	Node* TAIL;
public:
	SinglyLinkedList() {  // DEFAULT CONSTRUCTOR TO INTIALIZE LIST
		HEAD = NULL;
		TAIL = NULL;
	}
	Node* CreateNode(int data) {  // FUNCTION THAT CREATES AND RETURNS A NEW NODE
		Node* temp = new Node(data);
		return temp;
	}
	void InsertAtStart(int data) {  // INSERT NODE AT START 
		Node* temp = CreateNode(data);  // CREATING A NODE
		if (HEAD == NULL) {  // IF THE LIST IS EMPTY
			HEAD = temp;
			TAIL = temp;
		}
		else {  // IF THE LIST IS NOT EMPTY
			temp->next = HEAD;
			HEAD = temp;
		}
	}
	void InsertAtEnd(int data) {  // INSERT NODE AT END 
		Node* temp = CreateNode(data);  // CREATING A NODE
		if (HEAD == NULL) {  // INSERTING IF THE LIST IS EMPTY
			HEAD = temp;
			TAIL = temp;
		}
		else {  // IF THE LIST IS NOT EMPTY
			TAIL->next = temp;
			TAIL = temp;
		}
	}
	void InsertAtSpecificPosition(int data, int position) {  // INSERT NODE AT A SPECIFIC POSTION 
		if (position < 1) {  // IF POSITION IS LESS THAN OR EQUAL TO 0
			cout << "\nInvalid Postion! Inserting At Start." << endl;
			InsertAtStart(data);
			return;
		}
		Node* curr = HEAD, * prev = HEAD; // TWO POINTERS FOR TRAVERSING TO THE POSITION

		for (int count = 1; count < position; count++) { // REACHINNG THE DESIRED POSITION
			if (curr == NULL) { // IF INDEX IS GREATER THAN THE LENGTH OF LIST
				cout << "\nInvalid Position! Inserting At End." << endl;
				InsertAtEnd(data);
				return;
			}
			prev = curr;
			curr = curr->next;
		}
		Node* temp = CreateNode(data);
		prev->next = temp;  //  |
							//	|->  INSERTING AT SPECIFIC POSITION
		temp->next = curr;	//  |
	}
	void DeleteAtStart() {  // DELETE NODE AT START 
		if (HEAD == NULL) { // IF THE LIST IS EMPTY
			cout << "Nothing to Delete List is Already Empty." << endl;
			return;
		}
		if (HEAD->next == NULL) { // IF THERE IS ONLY ONE ELEMENT
			delete HEAD;
			HEAD = TAIL = NULL;
			return;
		}
		Node* temp = HEAD;  //  |
		HEAD = HEAD->next;  //	|->  DELETEING AT START
		delete temp;	    //	|
	}
	void DeleteAtEnd() {  // DELETE NODE AT END 
		if (TAIL == NULL) {  // IF THE LIST IS EMPTY
			cout << "Nothing to Delete List is Already Empty." << endl;
			return;
		}
		if (HEAD->next == NULL) {  // IF THERE IS ONLY ONE ELEMENT
			delete HEAD;
			HEAD = TAIL = NULL;
			return;
		}
		Node* temp = HEAD;
		while (temp->next != TAIL) { // REACHING THE ELEMENT PREVIOUS TO TAIL  
			temp = temp->next;
		}
		TAIL = temp;		//  |
		temp = temp->next;	//  |	
		TAIL->next = NULL;	//  ||->  DELETEING AT END
		delete temp;		//  |
	}
	void DeleteAtSpecificPosition(int position) {  // DELETE NODE AT A SPECIFIC POSTION  
		if (position < 1) {  // DELETEING IF POSITION IS 0 OR LESS
			cout << "\nInvalid Postion! Deleting At Start." << endl;
			DeleteAtStart();
			return;
		}
		Node* curr = HEAD, * prev = HEAD;
		for (int count = 1; count < position; count++) {  // REACHINNG THE DESIRED POSITION
			if (curr == NULL) {  // IF INDEX IS GREATER THAN THE LENGTH OF LIST
				cout << "Invalid Position! Deleting At End." << endl;
				DeleteAtEnd();
				return;
			}
			prev = curr;
			curr = curr->next;
		}
		Node* temp = curr;	//  |
		curr = curr->next;	//  |
		prev->next = curr;	//  ||-> DELETEING PROCESS
		delete temp;		//  |
	}
	void PrintList() {
		Node* curr = HEAD; // POINTER TO TRAVERSE
		cout << "DATA : ";
		while (curr != NULL) { // REACHING END OF THE LIST WHILE PRINTING ON THE SAME TIME
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};
int main() {
	SinglyLinkedList l1;

	l1.InsertAtEnd(1);
	l1.InsertAtEnd(2);
	l1.InsertAtEnd(3);

	cout << "CUURENT LIST " << endl;
	l1.PrintList();
	cout << "--------------------------------------------------------------" << endl;
	cout << "INSERTING AT START" << endl;
	l1.InsertAtStart(4);
	l1.PrintList();
	cout << "--------------------------------------------------------------" << endl;
	cout << "INSERTING AT END" << endl;
	l1.InsertAtEnd(5);
	l1.PrintList();
	cout << "--------------------------------------------------------------" << endl;
	cout << "INSERTING AT SPECIFIC POSITION" << endl;
	l1.InsertAtSpecificPosition(6, 3);
	l1.PrintList();
	cout << "--------------------------------------------------------------" << endl;
	cout << "DELETEING AT START" << endl;
	l1.DeleteAtStart();
	l1.PrintList();
	cout << "--------------------------------------------------------------" << endl;
	cout << "DELETEING AT END" << endl;
	l1.DeleteAtEnd();
	l1.PrintList();
	cout << "--------------------------------------------------------------" << endl;
	cout << "DELETEING AT SPECIFIC POSITION" << endl;
	l1.DeleteAtSpecificPosition(3);
	l1.PrintList();
}