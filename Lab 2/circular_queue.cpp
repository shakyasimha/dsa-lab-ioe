// Code written by Sushovan Shakya (THA075BEI046)
// DSA Lab 2: Circular Queue

#include <iostream>

using namespace std;

int max_size = 100;

class Queue {
	int rear, front;
	int *queue;
	int size;

public:
	Queue(int size) {
		front = -1;
		rear = -1;
		this->size = size;

		queue = new int[this->size];
	}

	bool isEmpty() { return(front == -1); }

	void enque(int data) {

		// We know that the next element in a circular queue is given by (rear + 1) % size
		if(((rear+1) % size) == front) {
			cout << "Queue full" << endl;
			return;
		}
		else if (front == -1) {
			front = rear = 0;
			queue[rear] = data;
		}
		else {
			queue[rear] = data;
			rear = (rear + 1) % size;
		}
	}
	
	void deque() {
		int deque_item = 0;

		if(isEmpty()) {
			cout << "Empty queue" << endl;
		}
		else if (front == rear) {
			deque_item = queue[front];
			front = rear = -1;
		}
		else {
			deque_item = queue[front];
			front = (front + 1) % size;
		}
	}

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
		else if(front <= rear) {
			for(int i = front; i <= rear; ++i) {
				cout << " " << queue[i];
			}
		}
		else {
			for(int i = front; i < size; ++i) {
				cout << " " << queue[i];
			}
			for(int i = 0; i <= rear; ++i) {
				cout << " " << queue[i];
			}
		}
		cout << endl;
	}

	~Queue() {
		delete[] queue;
	}
};

int main() {

	Queue *queue_obj = new Queue(max_size);

	for(int i = 0; i < 6; ++i) {
		queue_obj->enque(rand() % 7);
	}

	queue_obj->display();
	cout << endl;

	cout << "List after deque: " << endl;
	queue_obj->deque();
	queue_obj->frontOf();
	queue_obj->display();
	cout << endl;

	delete queue_obj;

	return 0;
}