// Code written by Sushovan Shakya
// DSA Lab 2: Array Implementation of Queue

#include <iostream>
using namespace std;

int max_size = 100;

class Queue {
	int front, rear;
	int *queue;

public:
	Queue() {
		front = 0;
		rear = 0;
		queue = new int[max_size];
	}

	bool isEmpty() { 
		return(front == rear); 
	}

	bool isFull() { 
		return(rear == max_size - 1); 
	}

	// Enque method
	void enque(int data) {
		if(isFull()) {
			cout << "Overflow" << endl;
			return;
		}
		else{
			queue[rear] = data;
			++rear;
		}
	}

	// Deque method
	void deque() {
		int deque_value = 0;

		if(isEmpty()) {
			cout << "Underflow" << endl;
		}
		else {
			deque_value = queue[front];

			for(int i = 0; i < rear - 1; ++i) {
				queue[i] = queue[i+1];
			}

			--rear;
			cout << deque_value << " dequed from the queue." << endl;
		}
	}


	// For returning front of the queue
	void frontOf() {
		if(isEmpty()) {
			cout << "Queue empty." << endl;
			return;
		}
		else {
			cout << "Front of the queue: " << queue[front] << endl;
		}
	}

	void display() {
		if(isEmpty()) {
			cout << "Queue empty." << endl;
			return;
		}
		else {
			for(int i = front; i < rear; ++i) {
				cout << queue[i] << " ";
			}
		}
	}

	~Queue() {
		delete[] queue;
	}
};

int main() {
	Queue *queue_obj = new Queue();

	for(int i = 0; i < 6; ++i) {
		queue_obj->enque(rand() % 7);
	}

	queue_obj->display();

	cout << endl;
	queue_obj->deque();
	queue_obj->frontOf();
	cout << "List after deque: " << endl;
	queue_obj->display();
	cout << endl;

	delete queue_obj;
	return 0;
}