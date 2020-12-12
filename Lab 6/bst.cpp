/* 
    Create a BST of N Integers
    Code written by Sushovan Shakya (THA075BEI046)
    Question 1, 2, 3 of Lab 6 all in the same code
*/

#include <iostream>

struct Node {
    int data;
    struct Node *left, *right;

    Node() {
        data  = 0;
        left  = NULL;
        right = NULL;
    }
};

class BST {
    public:
        Node *rootPtr;

        BST() {
            rootPtr = NULL;
        }

        /*
            Here:
            insert() => inserting new data
            search() => searching specified data
            largest() => finding the largest node
            purge() => deleting specified data
            display_pre() => pre-order display
            display_post() => post-order display
            display_in() => in-order display
        */

        void insert(Node *rootPtr, int data);
        void search(Node *rootPtr, int data);
        Node* largest(Node *rootPtr);
        void purge(Node *rootPtr, int data);
        void display_pre(Node *rootPtr);
        void display_post(Node *rootPtr);
        void display_in(Node *rootPtr);
};

// For insertion of data
void BST::insert(Node *rootPtr, int data) {
    Node *newNode;

    if(rootPtr == NULL) {
        newNode = new Node;
        newNode->data  = data;
        newNode->left  = NULL;
        newNode->right = NULL;
    }
    else {
        if(data < rootPtr->data) {
            insert(rootPtr->left, data);
        }
        else {
            insert(rootPtr->right, data);
        }
    }
}

// For searching the element 
void BST::search(Node *rootPtr, int data) {
    if(rootPtr == NULL || data == rootPtr->data) {
        std::cout << "\nData not found!" << std::endl;
    }
    else {
        std::cout << rootPtr->data << " has been found" << std::endl;
    }
}

// For finding the largest 
Node* BST::largest(Node *rootPtr) {
    if(rootPtr->right == NULL) {
        return rootPtr;
    }
    else {
        return largest(rootPtr->right);
    }
}

// For deleting the specified data
void BST::purge(Node *rootPtr, int data) {
    if(rootPtr == NULL) {
        std::cout << "Error, value not found" << std::endl;
    }
    else if(data < rootPtr->data) {
        purge(rootPtr->left, data);
    }
    else if(data > rootPtr->data) {
        purge(rootPtr->right, data);
    }
    else if(rootPtr->left && rootPtr->right) {
        Node *newNode = largest(rootPtr->left);
        rootPtr->data = newNode->data;
        purge(rootPtr->left, newNode->data);
    }
    else {
        Node *newNode = rootPtr;
        
        if(rootPtr->left == NULL && rootPtr->right == NULL) {
            rootPtr = NULL;
        }
        else if(rootPtr->left != NULL) {
            rootPtr = rootPtr->left;
        }
        else {
            rootPtr = rootPtr->right;
        }

        delete newNode;
    }
}

// Pre-order display
void BST::display_pre(Node *rootPtr) {
    if(rootPtr != NULL) {
        std::cout << " -> " << rootPtr->data;
        display_pre(rootPtr->left);
        display_pre(rootPtr->right);
    }
}

// Post-order display
void BST::display_post(Node *rootPtr) {
    if(rootPtr != NULL) {
        display_post(rootPtr->left);
        display_post(rootPtr->right);
        std::cout << "->" << rootPtr->data;
    }
}

// In-order display
void BST::display_in(Node *rootPtr) {
    if(rootPtr != NULL) {
        display_in(rootPtr->left);
        std::cout << "->" << rootPtr->data;
        display_in(rootPtr->right);        
    }
}

int main() {
    BST *tree = new BST;
    
    int some_data, choice = 1;

    while (choice != 7) {
        std::cout << "Binary Search Tree" << std::endl << std::endl;
        std::cout << "1: Insert data " << std::endl;
        std::cout << "2: Search data" << std::endl;
        std::cout << "3: Delete data" << std::endl;
        std::cout << "4: Display pre-order" << std::endl;
        std::cout << "5: Display post-order" << std::endl;
        std::cout << "6: Display in-order" << std::endl;
        std::cout << "7: Exit" << std::endl << std::endl;

        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter data to insert: ";
                std::cin >> some_data;
                tree->insert(tree->rootPtr, some_data);
            case 2:
                std::cout << "Enter data to search: ";
                std::cin >> some_data;
                tree->search(tree->rootPtr, some_data);
            case 3:
                std::cout << "Enter data to delete: ";
                std::cin >> some_data;
                tree->purge(tree->rootPtr, some_data);
            case 4:
                std::cout << "Pre-order display" << std::endl;
                tree->display_pre(tree->rootPtr);
            case 5:
                std::cout << "Post-order display" << std::endl;
                tree->display_post(tree->rootPtr);
            case 6:
                std::cout << "In-order display" << std::endl;
                tree->display_in(tree->rootPtr);
            case 7:
                break;
        }
    }

    delete tree;
    return 0;
}