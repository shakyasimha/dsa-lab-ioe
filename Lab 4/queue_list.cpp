/*
	Lab 4: Implementation of Queue using Linked List
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

// Queue class
class Queue {

	Node *front, *rear;  		// Two pointers that point to the front and rear of the Queue

public:

	Queue() {
		front = null;
		rear  = null;
	}

	bool isEmpty() { return(front == null); }

	// Method for pushing data into the queue
	void enque(int data) {
		Node *temp = new Node;
		temp->data = data;

		if(isEmpty()) {
			front = temp;			// If the list is empty, and new data is inserted,
			rear  = temp;			// Front and Rear both point to the same node
		}
		else {
			rear->next = temp;		// When queue is updated, temp becomes the new rear node
			rear = temp;
		}
	}

	// Method for removing data from front of the queue
	void deque() {
		if(isEmpty()) {
			cout << "Queue empty...." << endl;
		}
		else {
			Node *temp = new Node;

			temp  = front;
			front = front->next;		// Front points to the node second from the original front node

			// This condition applies when queue has only one element
			// Since front and rear point to the same element, rear also becomes null
			if(front == null) {
				rear = null;
			}

			delete temp;
		}
	}

	// Returns the front of the queue
	void frontof() {
		if(isEmpty()) {
			cout << "Queue empty...." << endl;
		}
		else {
			cout << "Front of the queue: " << front->data << endl;
		}
	}

	// Traversing and displaying the queue 
	void display() {
		if(isEmpty()) {
			cout << "Queue empty...." << endl;
		}
		else {
			Node *temp = front;
				
			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while(temp->next != null);

			cout << endl;
		}
	}
};

int main() {

	Queue *queue_obj = new Queue;

	for(int i = 0; i < 6; ++i) {
		queue_obj->enque(rand() % 7);
	}

	queue_obj->frontof();
	cout << "Queue: ";
	queue_obj->display();
	queue_obj->deque();
	cout << "Queue after deque: ";
	queue_obj->display();
	cout << endl;

	delete queue_obj;
	return 0;
}