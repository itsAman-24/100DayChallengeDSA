//WAP to sort the stack(using recursion)

#include <bits/stdc++.h> 
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    sortStack(stack);
    
    sortedInsert(stack, num);
}


int main() {
    stack<int> myStack;

    // Push some elements onto the stack (you can modify this part)
    myStack.push(3);
    myStack.push(1);
    myStack.push(4);
    myStack.push(2);
    myStack.push(5);

    cout << "Original Stack: ";
     while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    // Sort the stack
    sortStack(myStack);

    cout << "Sorted Stack: ";
     while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}



