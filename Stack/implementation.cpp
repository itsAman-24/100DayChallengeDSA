//WAP to show implementation of stack using arrays

#include <bits/stdc++.h>
using namespace std;
#define MAX 4       // Using #define processor
int stack_arr[MAX]; // Global declaration
int top = -1;       // Indicating the stack is empty

int isEmpty() {          //checks Stack is empty or not 
    if (top == -1)
        return 1;

    else
        return 0;
}

int isFull() {          //checks Stack is full or not
    if (top == MAX - 1)
        return 1;

    else
        return 0;
}



// PUSH function
void push(int data)
{
    if (isFull())
    {
        cout << "Your stack is full..No place for insertion anymore." << endl;
        return;
    }

    top = top + 1;
    stack_arr[top] = data;
}

// POP function
int pop()
{
    if (isEmpty())
    {
        cout << "Your stack is underflowed..." << endl;
        exit(1); // this exit function with 1 as parameter simply means abnormal termination of program
    }

    int value = stack_arr[top];
    top = top - 1;

    return value;
}

void print1()
{
    for (int i = 0; i < MAX; i++)
    {
        cout << stack_arr[i] << "  ";
    }
    cout << endl;
}

void print2()
{
    int i = 0;
    for (top; top > -1; top--)
    {
        cout << stack_arr[i] << "  ";
        i++;
    }
}

int main()
{

    push(4);
    push(5);
    push(7);
    push(12);
    
    print1();

    push(26);

    print1();
    
    cout << endl << "The poped element is-> " << pop() << endl << endl;
    cout << endl << "The poped element is-> " << pop() << endl << endl;
    cout << endl << "The poped element is-> " << pop() << endl << endl;
    cout << endl << "The poped element is-> " << pop() << endl << endl;
    cout << endl << "The poped element is-> " << pop() << endl << endl;

    print2();
}
