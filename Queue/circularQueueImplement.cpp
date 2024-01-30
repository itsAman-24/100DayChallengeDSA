//WAP to show the implementation of circular Queue using array
#include <bits/stdc++.h> 
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n){
       size = n;
       arr = new int[size];
       front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
            return false;
        }

        else if(front == -1) {
            front = rear = 0;
        }

        else if(rear == size -1 && front != 0) {
            rear = 0;
        }

        else {
            rear ++;
        }

        arr[rear] = value;

        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1) {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear) {
            front = rear = -1;
        }

        else if(front == size-1) {
            front = 0;
        }

        else {
            front ++;
        }

        return ans;
    }
};

int main() {
    // Example usage of the CircularQueue class
    CircularQueue cq(5); // Creating a circular queue of size 5

    // Enqueue some elements
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);

    // Dequeue elements
    cout << cq.dequeue() << endl;
    cout << cq.dequeue() << endl;

    // Enqueue more elements
    cq.enqueue(4);
    cq.enqueue(5);

    // Dequeue elements
    cout << cq.dequeue() << endl;
    cout << cq.dequeue() << endl;

    return 0;
}