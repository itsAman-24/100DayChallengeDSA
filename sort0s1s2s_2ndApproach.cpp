// write a program to sort os,1s,2s in a Linked List (CODE STDIO)

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtTail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void sortlinkedlist(node* &head, node* &tail) {
    node* zerohead = new node(-1);
    node* zerotail = zerohead;

    node* onehead = new node(-1);
    node* onetail = onehead;

    node* twohead = new node(-1);
    node* twotail = twohead;

    

}

int main()
{
    node *n1 = new node(1);

    node *head = n1;
    node *tail = n1;

    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtHead(head, 2);
    insertAtTail(tail, 1);
     
    cout << "Linked list before Sorting -> " << endl;
    print(head);

    cout << endl << endl;
    cout << "Your sorted linked list is -> " << endl;

    
}