/*
	DSA Lab 4: Implementation of Singly Linked List
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

		temp->data = data;
		temp->next = null;

		if(isEmpty()) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}

	void remove() {
     	Node *temp = head;

	    if(isEmpty()) {
	        cerr << "Error, the list is empty" << endl;
	    }
	    else {
	        while(temp->next->next != null)
	        {
	            temp = temp->next;
	        }

	        temp->next = null;
	    }
	}

	void display() {
		
		if(isEmpty()) {
			cerr << "Error, the list is empty!" << endl;
		} 
		else {
			Node *temp = new Node;
			temp = head;

			do {
				cout << temp->data << " ";
				temp = temp->next;
			} while (temp->next != null);
		}
	}
};

int main() {

	List *list_obj = new List;
	char option, query;
	int some_data;

	cout << "Enter options below: " << endl;
	cout << "1. Insert data on list" << endl;
	cout << "2. Remove data from list" << endl;
	cout << "3. Display the list" << endl;

	cin >> option;

	if(option == '1') {

		do {
			cout << endl << "Enter data: ";
			cin  >> some_data;

			list_obj->insert(some_data);

			cout << "Do you want to add more elements? [Y/N] ";
			cin  >> query;
		} while(query != 'N' || query != 'n');
	}
	else if (option == '2') {
		list_obj->remove();
	}
	else if (option == '3') {
		list_obj->display();
	}
	else {
		cerr << "Error, incorrect option" << endl;
	}

	return 0;
}