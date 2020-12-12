/*
	DSA Lab 4: Implementation of Circular Linked List
	Code written by Sushovan Shakya (THA075BEI046)
*/

#include <iostream>

#define null NULL 

using namespace std;

struct Node {
	int data;
	Node *next;
};

class List {

private:
	Node* head, *tail;

public:

	List() {
		head = null;
		tail = null;
	}

	bool isEmpty() { return (head == null); }

	void insert(int data) {
		Node *temp = new Node;
		Node *prev = head;

		temp->data = data;
		temp->next = head;

		if(isEmpty()) {
			temp->next = temp;
		}
		else {
			do {
				prev = prev->next;
			} while(prev->next != null);
			prev->next = temp;
		}

		head = temp;
	}

	void display() {
		
		if(isEmpty()) {
			cerr << "Error, the list is empty!" << endl;
		} 
		else {
			Node *temp = head;

			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp->next != head);
		}
	}
};

int main() {

	List *list_obj = new List;

	for(int i = 0; i < 7; ++i) {
		list_obj->insert(rand() % 7);
	}
	list_obj->display();

	return 0;
}