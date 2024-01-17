//WAP to Reverse the stack by using Recursion

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &stack, int num) {
    //base case 
    if(stack.empty()) {
        stack.push(num);
        return ;
    }

    int top = stack.top();
    stack.pop();

    //recurssive call
    insertAtBottom(stack,num);

    stack.push(top);

}

void reverseStack(stack<int> &stack) {
    //base case
    if(stack.empty()) {
        return ;
    }

    int num = stack.top();
    stack.pop();

    //recurssive call
    reverseStack(stack);

    // for inserting the num at bottom of the stack
    insertAtBottom(stack,num);
}


int main() {
    // Example Usage
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    // Display original stack
    cout << "Original Stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    // Push the elements again
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    // Reverse the stack
    reverseStack(myStack);

    // Display reversed stack
    cout << "Reversed Stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}