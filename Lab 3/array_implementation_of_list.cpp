/*
    Lab 3, Question 1: Array implementation of List
    Code written by Sushovan Shakya (THA075BEI046)
*/

#include<iostream>
using namespace std;

int max_size = 10;

struct nodeType {
    int data;
    int next;
};

class List
{
    int head = 0;
    int avail =0;
    nodeType node[max_size];
public:
    List() {
        for(int i = 0; i < max_size; i++) {
            node[i].data = 0;
            node[i].next = i+1;
        }
        node[max_size-1].next = -1;
    }

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

    void create_list() {
        int val;
        cout << "Enter the data (-1 to stop): " << endl;
        
        do {
            if(avail == -1)
                break;
            cout<<endl<<"enter the data: ";
            cin>>val;
            if(val != -1)
                insert_node(val);
            
        } while(val != -1);
    }

    void insert_node(int val) {
        int p = get_node();

        if(p == -1) {
            cout << "Overflow!!" << endl;
        }
        else if(p == head) {
            node[p].data = val;
            node[p].next = -1;
        }
        else {
            node[p].data = val;
            node[p].next = -1;
            int temp = head;

            if(node[temp].next == -1) {
                node[temp].next = p;
            }
            else {
                while(node[temp].next != -1) {
                
                temp = node[temp].next;
            }
        }
    }

    void insert_after(int n, int val) {
        int p = get_node();

        if(p == -1) {
            cout << "Overflow" << endl;
        }
        else {
            node[p].data = val;
            node[p].next = node[n].next;
            node[n].next = p;
        }
    }

    void delete_node(int n) {
        if(n == head) {
            head = node[n].next;
            free_node(n);
        }
        else {
            int temp = head;

            while(1) {
                if(node[temp].next == n) {
                    node[temp].next = node[n].next;
                    free_node(n);
                    break;
                }
                temp = node[temp].next;
            }
        }
    }

    void delete_after(int n) {
        if(node[n].next == -1) {
            cout <<  "List empty" << endl;
        }
        else if(n == head) {
            int temp = node[head].next;
            node[head].next = node[temp].next;
            free_node(temp);
        }
        else {
            int temp = head;
            
            if(node[temp].next == n) {
                temp = node[n].next;
                node[n].next = node[temp].next;
                free_node(temp);
            }            
            else {
                while(node[temp].next != -1) {
                    temp = node[temp].next;
                }
            }
        }
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
};

int main() {
    List list_obj;
    int n, option;
    int val;
    
    do {
        cout << "1. Create List" << endl;
        cout << "2. Insert a node" << endl;
        cout << "3. Insert after a given node" << endl;
        cout << "4. Delete a given node" << endl;
        cout << "5. Delete after a given node" << endl;
        cout << "6. Exit" << endl;
        cout << "   Enter your option: ";
        cin >> option;

        switch(option) {
        case 1:
            {
                listobj.create_list();
                break;
            }
        case 2:
            {
                cout << endl << "Enter the node value: ";
                cin >> val;
                list_obj.insert_node(val);
                break;
            }
        case 3:
            {
                cout << endl << "Enter the node after which you want to add the node: ";
                cin >> n;
                cout << "Enter the new node value: ";
                cin >> val;
                list_obj.insert_after(n, val);
                break;
            }
        case 4:
            {
                cout << endl << "Enter the node to delete: ";
                cin >> n;
                list_obj.delete_node(n);
                break;
            }
        case 5:
            {
                cout << endl << "Enter the node after which you want to delete a node ";
                cin >> n;
                list_obj.delete_after(n);
                break;
            }
        case 6:
            {
                exit(0);
            }
        default:
            {
                break;
            }
        }
        listobj.display();
    } while(option != 6);

    return 0;
}
