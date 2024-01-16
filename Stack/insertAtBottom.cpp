// WAP Insert An Element At Its Bottom In A Given Stack by using recurssion

#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>& myStack, int x) {

    //Base case
    if(myStack.empty()) {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    //Recurssive call
    solve(myStack,x);

    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}

int main() {
    stack<int> myStack;

    // Push some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    cout << "Original Stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;
    
    int number;
    cout << "Enter the number that you want to insert at bottom of the stack : ";
    cin >> number;

    pushAtBottom(myStack,number);

    cout << "Stack after insertion at bottom : ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    
    return 0;

}
