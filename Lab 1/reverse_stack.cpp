#include <iostream>

#define MAX 100

using namespace std;

class Stack {
	int _stack_[MAX];
	int top;

public:
	Stack() { top = -1; }
	bool isEmpty { return (top == -1); }

	void push(int data) {
		if(top == MAX - 1) {
			cout << "Stack overflow" << endl;
		}
		else {
			_stack_[++top] = data;
			cout << "Pushed into the stack. " << endl;
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

    void display() {
        cout << "Stack: " << endl;

        for(int i = top; i > -1; --i)
        {
           cout << _stack_[i] << endl;
        }
    }

    void reverse()
    {
        cout << "Reverse stack: " << endl;

        for (int i = 0; i <= top; i++)
        {
            cout << _stack_[i] << endl;
        }
    }
}

int main() {
	Stack stack_obj;
	int rand_int; 

	for(int i = 0; i <=7; ++i) {
		rand_int = rand() / 7;
		stack_obj.push(rand_int);
	}

	stack_obj.display();
	stack_obj.reverse();

	return 0;
}