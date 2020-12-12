/*
	DSA Lab 4: Linked List implementation of Stack
	Code written by Sushovan Shakya (THA075BEI046)
*/
#include <iostream>
using namespace std;

#define null NULL 

// Struct for storing Node of the linked list
struct Node {
	Node *next;
	int data;
};

// Stack class
class Stack {
private:
	Node *head;

public:

	Stack() {
		head = null;
	}

	bool isEmpty() { return(head == null); }

	void push(int data) {
		Node *temp = new Node;

		temp->data = data;

		if(!isEmpty()) {
			temp->next = head;
		}
		else {
			temp->next = null;
		}

		head = temp;
	}

	void pop() {
		
		if(isEmpty()) {
			cerr << "Error, stack underflow!" << endl;
		}
		else {
			Node *temp = new Node;
			temp = head;

			head = head->next;

			delete temp;
		}
	}

	void peek() {
		cout << head->data << endl;
	}

	void display() {
		Node *temp = new Node;
		temp = head;

		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while(temp->next != null);
		
		cout << endl;
	}
};

int main() {

	Stack *stack_obj = new Stack;

	for(int i = 0; i < 6; ++i) {
		stack_obj->push(rand() % 7);
	}

	stack_obj->peek();
	cout << "StackL ";
	stack_obj->display();
	stack_obj->pop();
	cout << "Stack after popping: ";
	stack_obj->display();
	cout << endl;

	delete stack_obj;
	return 0;
}