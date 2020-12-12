#include <iostream>

#define MAX 100

using namespace std;

class Stack {
	int top;
	int _stack_[MAX];

public:
	Stack() {
		top = -1;
	}

	bool isEmpty() {
		return (top == -1);
	}

	void push(int data) {
		if(top == MAX - 1) {
			cout << "Stack Overflow" << endl;
		}
		else {
			_stack_[++top] = data;
			cout << "Pushed into the stack." << endl;
		}
	}

	void pop() {
		int pop_value;

		if(top < 0) {
			cout << "Stack underflow" << endl;
		}
		else {
			pop_value = _stack_[--top];
			return pop_value;
		}
	}

	void peek() {
		if(top < 0) {
			cout << "Stack underflow" << endl;
		}
		else {
			return _stack_[top];
		}
	}
}
int main() {

	Stack stack_obj;

	// Pushing values to the stack
	for(int i = 0; i < 5; ++i) {
		stack_obj.push(i);
	}

	cout << endl;
	cout << stack_obj.pop() << " has been popped." << endl;
	cout << "Top of stack: " << stack_obj.peek() << endl;

	return 0;
}