// WAP to show the implementation of Queue using array

#include <iostream>
using namespace std;

class Queue {
public:
    int* Queue_arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        Queue_arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
            return;
        }

        Queue_arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if (qfront == rear) {
            return -1; // indicating that the queue is empty
        } else {
            int ans = Queue_arr[qfront]; // storing the element which is going to be removed

            Queue_arr[qfront] = -1;
            qfront++;

            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (qfront == rear) {
            return -1; // indicating that the queue is empty
        } else {
            return Queue_arr[qfront];
        }
    }
};

int main() {
    // You can test your Queue implementation here
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    cout << "Front element: " << myQueue.front() << endl;

    cout << "Dequeued element: " << myQueue.dequeue() << endl;

    cout << "Front element after dequeue: " << myQueue.front() << endl;

    return 0;
}
