/*
	DSA Lab 4: Subtraction and Addition of Polynomials using Linked Lists
	Code written by Sushovan Shakya (THA075BEI046)
*/

#include <iostream>

#define null null 

using namespace std;

struct Node {
	int coeff;
	int x_exp;
	int y_exp;
	int z_exp;
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

	void insert(int coeff, int x, int y, int z) {
      	Node *new_node = new Node;
        Node *temp = head;
        
        new_node->coeff = coeff;
        new_node->x_exp = x;
        new_node->y_exp = y;
        new_node->z_pow = z;

        if(isEmpty()){
            new_node->next=head;
            head = new_node;
        }
        else{
            do {
                new_node = new_node->next;
            } while(new_node->next! = null);

            new_node->next = temp;
            temp->next =null;
        }

	}

    List operator+(List &exp){
        List temp;
        Node node_1 = head;
        Node node_2 = exp.head;

        while(node_1 != null){
            temp.insert(node_1->coeff, node_1->x_exp, node_1->y_exp, node_1->z_exp);
            node_1 = node_1->next;
        }

        while(node_2! = null){
            node_1 = temp.head;
            while(node_1! = null){
                if((node_1->x_exp == node_2->x_exp) && (node_1->y_exp == node_2->y_exp) && (node_1->z_exp == node_2->z_exp)){
                    break;
                }
                node_1 = node_1->next;
            }
            if(node_1 == null){
                temp.insert(node_2->coeff, node_2-> x_exp, node_2->y_exp, node_2->z_exp);
            }
            else{
                node_1->coeff += node_2->coeff;
            }
            node_2 = node_2->next;
        }

        return temp;
    }


    List operator-(List &exp){
        List temp;
        Node node_1 = head;
        Node node_2 = exp.head;

        while(node_1! = null){
            temp.insert(node_1->coeff, node_1->x_exp, node_1->y_exp, node_1->z_exp);
            node_1 = node_1->next;
        }

        while(node_2! = null){
            node_1 = temp.head;

            while(node_1! = null){
                if((node_1->x_exp == node_2->x_exp) && (node_1->y_exp == node_2->y_exp) && (node_1->z_exp == node_2->z_exp)){
                    break;
                }
                node_1 = node_1->next;
            }
            if(node_1 == null){
                temp.insert((node_2->coeff*-1), node_2->x_exp, node_2->y_exp, node_2->z_exp);
            }
            else{
                node_1->coeff -= node_2->coeff;
            }
            node_2 = node_2->next;
        }

        return temp;
    }



    void display(){
        Node *temp = head;

        cout << endl; 

        while(temp! = null){
            if(p->coeff < 0)
                cout << "- " << (p->coeff*-1) << "x^" << p->x_exp << "y^" << p->y_exp << "z^" << p->z_exp <<" ";
            else
                cout << "+ " << p->coeff << "x^" << p->x_exp << "y^" << p->y_exp << "z^" << p->z_exp <<" ";
            temp = temp->next;
        }

        cout << endl;
 	}
};

int main() {

}