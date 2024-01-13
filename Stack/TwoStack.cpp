//WAP to implement and show the functions and behaviour of twostack inside a single array

#include<bits/stdc++.h>
using namespace std;

class TwoStack {
    int * arr;
    int top1;
    int top2;
    int size;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
       if(top1 != -1) {
           int ans = arr[top1];
           top1--;
           return ans;
       }

       else {
           return -1;
       }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 != size) {
           int ans = arr[top2];
           top2++;
           return ans;
       }

       else {
           return -1;
       }
    }
};

int main() {
    // Create an instance of the TwoStack class with a specified size
    TwoStack myTwoStack(5);

    // Push elements onto stack 1
    myTwoStack.push1(1);
    myTwoStack.push1(2);
    myTwoStack.push1(3);

    // Push elements onto stack 2
    myTwoStack.push2(4);
    myTwoStack.push2(5);

    // Pop elements from stack 1 and print the results
    cout << "Pop from Stack 1: " << myTwoStack.pop1() << endl;
    cout << "Pop from Stack 1: " << myTwoStack.pop1() << endl;
    cout << "Pop from Stack 1: " << myTwoStack.pop1() << endl;

    // Pop elements from stack 2 and print the results
    cout << "Pop from Stack 2: " << myTwoStack.pop2() << endl;
    cout << "Pop from Stack 2: " << myTwoStack.pop2() << endl;

    return 0;
}