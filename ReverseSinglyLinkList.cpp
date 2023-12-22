//Write a program to reverse a singly linked list 

/* APPROACH : We will use three pointers approach named as ( previous, current, forward ) and changing the current nodes -> next pointer to previous 
,, after updating the next pointer of current node shift current to forward (current -> next) */

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d) {
        this->data = d;
        this->next = NULL;
    }


};

void insertAtHead(node* &head, int data) {
    node* newnode = new node(data);
    if(head == NULL) {
        head = newnode;
    }

    else {
        newnode -> next = head;
        head = newnode;
    }

}

void insertAtEnd(node* &tail, int data) {
    node* newnode = new node(data);
    if(tail == NULL) {
        tail = newnode;
    }

    else {
        tail -> next = newnode;
        tail = newnode;
    }
}

void print(node* head) {
    // cout << "PNDY"<< endl;
    node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}

node* ReverseList(node* &head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    else {
        node* previous = NULL;
        node* current = head;
        node* forward = NULL;

        while(current != NULL) {
            forward = current -> next;
            current -> next = previous;
            previous = current;
            current = forward;
        }

        head = previous;
        return head;
    }
}

int main() {
    node* newnode = new node(34);
    node* head = newnode;
    node* tail = newnode;

    insertAtHead(head,67);
    insertAtEnd(tail,56);
    insertAtEnd(tail,80);
    insertAtEnd(tail,90);
    cout << endl << "Here is your linked list ->  ";
    print(head);

    cout << endl << "Head is at: " << head -> data << endl;
    cout << "Tail is at : " << tail -> data << endl;
    cout << endl;

    cout << "Reversing the list ->  ";
    ReverseList(head);
    print(head);
   
}

