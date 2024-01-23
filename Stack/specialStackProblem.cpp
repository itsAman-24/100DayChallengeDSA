//WAP to Design a stack that supports getMin() in O(1) time and O(1) extra space.

#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <stack>

class SpecialStack {
    stack<int> s;
    int mini;

public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    int pop() {
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();
        s.pop();

        if (curr > mini) {
            return curr;
        } else {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }
        int curr = s.top();

        if (curr < mini) {
            return mini;
        } else {
            return curr;
        }
    }

    int getMin() {
        if (s.empty()) {
            return -1;
        }

        return mini;
    }
};

int main() {
    SpecialStack stack;

    stack.push(3);
    stack.push(5);
    cout << "Minimum: " << stack.getMin() << endl;

    stack.push(2);
    stack.push(1);
    cout << "Minimum: " << stack.getMin() << endl;

    cout << "Popped: " << stack.pop() << endl;
    cout << "Top: " << stack.top() << endl;
    cout << "Minimum: " << stack.getMin() << endl;

    return 0;
}
