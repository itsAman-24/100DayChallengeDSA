#include <bits/stdc++.h>
using namespace std;

class node {

    public:
    int data;
    node* next;

    node(int data) {
        // node* n1 = new node(data);

        this -> data = data;
        this -> next = NULL;
    }

    ~node() {
        int value = this -> data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }

        cout << "Deleting the data of node which is " << value << endl;
    }


};

void insertAtHead(node* &head ,int data) {
    node* temp = new node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(node* &tail, int data) {
    node* temp = new node(data);
    tail -> next = temp;
    tail = tail -> next;   // pointing tail to the last node of list
}


void print(node* &head) {

    if(head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    node* temp;
    temp = head;

    while(temp != NULL) {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}

void insertAtPosition(node* &head,node* &tail, int data, int posi) {

    if(posi == 1) {                // if user wants to insert at first position then we have to use insertAtHead function
        insertAtHead(head,data);
        return;
    }

    node* temp = head;
    int count = 1;

    while(count < posi-1) {
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL) {    // when inserting at end by this line of code we are updating the tail pointer nd pointing it to last node
        insertAtTail(tail,data);
    }

    node* insert = new node(data);

    insert -> next = temp -> next;
    temp -> next = insert;


}


void deleteNode(int position, node* & head, node* & tail) {
    //Code for deleting starting node
    if(position == 1) {
        node* temp = head;
        head = head -> next;
        
        temp -> next = NULL;
        delete temp;

    }
    
    //Code for deleting last and middle node
    else {
        node* previous = NULL;
        node* current = head;

        int count = 1;
        while(count < position) {
            previous = current;
            current = current->next;
            count++;
        }
        
        //when last node is deleted then this will change tail pointing on current last node
        if(current -> next == NULL) {
           tail = previous;
        }

        previous->next = current->next;
        
        current -> next = NULL;
        delete current;

    }
}

bool IsCircularList(node* head) {
    if(head == NULL) {     // if the list is empty we have to consider it as circular list
        return true;
    }

    node* temp = head -> next;   // taking next node after head as the temp node

    while(temp != NULL && temp != head) {    //traversing till temp is not NULL or it is not equal to head
        temp = temp -> next;
    }

    if(temp == head) {    // if it reaches the head it means it is circular list
        return true;
    }

    return false;

}


node* floyddeteactLoop1(node* head) {
    if(head == NULL) {
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    while(slow != NULL && fast != NULL) {
        fast = head -> next;

        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "Loop is present at: " << slow -> data << endl;
            return slow;
        }

    }

    return NULL;

    
}

int main() {
    
    node* n1 = new node(45);
   
    node* head = n1;
    node* tail = n1;

    
    insertAtHead(head,2000);
    insertAtHead(head,2001);
    insertAtTail(tail,148);
    insertAtTail(tail,4500);
    insertAtPosition(head,tail,0,1);
    insertAtPosition(head,tail,101,4);
    
    cout << "Befor deletion" << endl;
    print(head);

    cout << "HEAD " << head-> data << endl;
    cout << "Tail " << tail-> data << endl;  

    cout << "After deletion" << endl;
    deleteNode(5,head,tail);
    print(head);

    cout << "HEAD " << head-> data << endl;
    cout << "Tail " << tail-> data << endl; 


    cout << "Checking the nature of the list... " << endl; 

    if(IsCircularList(head)) {
        cout << endl << "This List is circular in nature " << endl;
    }
    
    else {
        cout << endl <<  "This List is not circular in nature " << endl;
    }
    
    

    floyddeteactLoop1(head);
}
