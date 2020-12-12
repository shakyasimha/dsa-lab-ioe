#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string exp) {
    stack <char> st;
    char c;

    // Traversing through the Expression
    for(int i=0; i< exp.length(); i++) {
        // Checking the input char
        if(exp[i] == '[' || exp[i] == '{'|| exp[i] == '(') {
            // Push the char in the stack
            st.push(exp[i]);
            continue; 
        }
        else {
            continue;
        }

        // If the char is not the opening bracket
        // // it must be closing bracket, so stack is not empty
        // if(st.empty())
        //  return true;

        switch(exp[i]) {

            case ')': {
                c = st.top();
                st.pop();
                if(c == '{' || c == '[')
                    return false;

                break;
            }
            case '}': {
                c = st.top();
                st.pop();
                if(c == '(' || c == '[')
                    return false;
                break;
            } 
            case ']': {
                c = st.top();
                st.top();
                if(c == '(' || c == '{')
                    return false;
                break;
            }

        }

    }

    // // check the status of the stack
    // if (st.empty())
        return true;
}

int main() {

    string exp = "([{(2+3))}]";

    // Checking the value return by the function
    if(isBalanced(exp))
        cout << "The expression is balanced" << endl;
    else if(!isBalanced(exp))
        cout << "The expression is not balanced" << endl;
    else 
        cout << "I don't know";
    return 0;
}