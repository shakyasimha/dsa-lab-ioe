/*
	Lab 4: Implementation of Priority Queue using Linked List
	Code written by Sushovan Shakya (THA075BEI046)
*/

#include <iostream>
using namespace std;

#define null NULL 

struct Node {
	Node *next;
	int data;
	int priority;
};

// Queue class
class Queue {

	Node *head;

public:

	Queue() {
		head = null;
	}

	bool isEmpty() { return(front == null); }

	void enque(int data, int prior) {
		Node *new_node = new Node;
		Node *temp = head;
		Node *prev = null;

		if(isEmpty()) {
			new_node->data = data;
			new_node->priority = prior;
			new_node->next = head;
			head = new_node;
		}
		else {
            while(temp->priority < prior){
                prev = temp;
                if(temp->next == NULL){
                    break;
                }
                temp = temp->next;
            }
            if(temp == NULL){
                new_node = new Node;
                new_node->next = prev;
                new_node->data = data;
                temp->priority = prior;
                head = temp;
            }
            else if(temp->priority >= prior){
               	new_node = new Node;
                prev->next = new_node;
                new_node->next = temp;
                new_node->data = data;
                new_node->priority = prior;
            }
            else{
                new_node = new Node;
                temp->next = new_node;
                new_node->data = data;
                new_node->priority = prior;
                new_node->next =NULL;
            }

		}
	}


	void deque() {
        Node *temp = head;

        if(isEmpty()) {
        	cerr << "Error, queue empty" << endl;
        }
        else {
        	Node *temp = head;
        	head = temp->next;

        	cout << temp->data << " dequed" << endl;
        	delete temp;
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

	cout << "Queue: ";
	queue_obj->display();
	queue_obj->deque();
	cout << "Queue after deque: ";
	queue_obj->display();
	cout << endl;

	delete queue_obj;
	return 0;
}