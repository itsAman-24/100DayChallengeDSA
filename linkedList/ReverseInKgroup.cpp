//Write a program to reverse the linked list in the group of K

#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int data) {
        this -> data = data;
        this -> next = NULL;
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
    node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " " << endl;
        temp = temp -> next;
    }
}

node* reverseInKgroup(node* head , int k) {
    //Base case
    if(head == NULL) {
        return NULL;
    }

    node* prev = NULL;
    node* current = head;
    node* forward = NULL;
    int count = 0;

    //Ek baar kaam kro baki recursion smbhal lega 
    while(current != NULL && count < k) {
        forward = current -> next;
        current -> next = prev;
        prev = current;
        current = forward;
        count++;
    }
    
    //Recusion will do the task will all other nodes in K group
    if(head != NULL) {
    head -> next = reverseInKgroup(forward,k);
    }
    
    return prev;

}


int main() {
    node* temp = new node(64);
    node* head = temp;
    node* tail = temp;

    
    insertAtEnd(tail,45);
    insertAtEnd(tail,50);
    insertAtEnd(tail,80);
    insertAtEnd(tail,95);

    print(head);

    cout << "After reversing in K group " << endl;

    head = reverseInKgroup(head,3);
    print(head);
   
}
