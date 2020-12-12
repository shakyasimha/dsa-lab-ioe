/*
    Lab 3, Question 2: List implementation of Queue
    Code written by Sushovan Shakya (THA075BEI046)
*/

#include<iostream>
using namespace std;

int max_size = 7;

struct nodeType {
    int data;
    int next;
};

int get_node() {
    if(avail == -1) {
        return -1;
    }
    else {
        int temp;
        temp = avail;
        avail = node[avail].next;
        return temp;
    }
}

void free_node(int n) {
    node[n].data = 0;
    node[n].next = avail;
    avail = n;
}

void display() {
    if(avail==0) {
        cout<<"List Underflow"<<endl;
    }

    do {
        cout << "Index: " << ptr << " Value: " << node[ptr].info << " Next: "<< node[ptr].next<<endl;
        ptr = node[ptr].next;
    } while(ptr != -1);
}

class Queue{
    private:
        int front, rear;
    public:
        Queue() {
            front = -1; 
            rear  = -1;
        }

        bool isempty(){
            return (front == -1);    
        }

        void enqueue() {
            int ptr;
            ptr = getnode();

            cout << "Enter an integer:";
            cin >> node[ptr].info;
            if(rear == -1)
                front = ptr;
            else
                node[rear].next = ptr;
            rear = ptr;
        }

        int dequeue() {
            int del_val, ptr;

            if(isempty()) {
                cout << "Underflow" << endl;
                exit(1);
            }
            else{
                del_val = node[front].info;
                ptr   = front;
                front = node[front].next;
                
                if(front==-1)
                    rear=-1;
                
                freenode(ptr);
                return del_val;
            }
        }

        int getfront(){
            return front;
        }
};

int main(){
    Queue queue_obj;
    int option = 1;
    int val, pos;

    for(int i = 0; i < max;i++){
        if(i == max-1){
            node[i].next = -1;
        }
        else{
            node[i].next = i+1;
        }
    }

    while(option != 0){
        cout << "Menu:" << endl;
        cout << "1 .Enqueue" << endl;
        cout << "2 .Dequeue" << endl;
        cout << "0 .Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch(choose){
        case 1:
            queue_obj.enqueue();
            break;
        case 2:
            val = queue_obj.dequeue();
            cout << val << " is dequeued" << endl;
            break;
        case 0:
            break;
        }
    }
    return 0;
}
