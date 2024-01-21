// Write a program to sort the 0s,1s,2s in a linked list (You cannot change the nodes data by any chance)

// INPUT -> Linked list 
// 2 1 0 2 0 1 

// OUTPUT -> Linked List
// 0 0 1 1 2 2 


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

void insertAtTail(node *&tail, node* & temp)
{
   // node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtTail2(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
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

void sortLinkedlist(node* &head, node* &tail) {
    //In this approach we will not play with the original data of any node 
    
    //Creating Dummy nodes for each seperate linked list
    node* zerohead = new node(-1);  
    node* zerotail = zerohead;

    node* onehead = new node(-1);
    node* onetail = onehead;

    node* twohead = new node(-1);
    node* twotail = twohead;

    node* temp = head;

    //Adding the nodes of 0s,1s,2s in their respective linked lists

    while (temp != NULL) {

        if(temp -> data == 0) {
            insertAtTail(zerotail,temp);
        }

        else if(temp -> data == 1) {
            insertAtTail(onetail,temp);
        }

        else if(temp -> data == 2) {
            insertAtTail(twotail,temp);
        }

        temp = temp -> next;
    }


    //Merging the Linked list 

    if(onehead -> next != NULL) { // it means linkedlist of 1 not empty
        zerotail -> next = onehead -> next;
    }

    else {  // it means linked list of 1 is empty
        zerotail -> next = twohead -> next;
    }

    onetail -> next = twohead -> next;
    twotail -> next = NULL;
    

    head = zerohead -> next;
    delete(zerohead);
    delete(onehead);
    delete(twohead);

    print(head);


}

int main()
{
    node *n1 = new node(1);

    node *head = n1;
    node *tail = n1;

    insertAtTail2(tail, 0);
    insertAtTail2(tail, 2);
    insertAtTail2(tail, 0);
    insertAtHead(head, 2);
    insertAtTail2(tail, 1);
     
    cout << "Linked list before Sorting -> " << endl;
    print(head);

    cout << endl << endl;
    cout << "Your sorted linked list is -> " << endl;

    sortLinkedlist(head, tail);
}