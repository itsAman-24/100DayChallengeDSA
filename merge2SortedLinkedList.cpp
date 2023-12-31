//Write a program to merge two different sorted Linked List in sorted order (code studio)

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

//1st Function to merge two sorted linked list 
node* mergeList1(node* &n1head, node* &n2head) {

    node* curr1 = n1head;
    node* next1 = curr1 -> next;

    node* curr2 = n2head;
    node* next2 = curr2 -> next;

    //if only one node is there in first linked list,,,( that's why we are checking this case in the starting of loop )
    if(next1 -> next == NULL ) {
        curr1 -> next = curr2;
        return curr1;
    }

    while(next1 != NULL && curr2 != NULL) {
        
        //checking that the node from second list lies between first two nodes (WINDOW) from first linked list

        if( (curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data ) ) {

            //placing node from second list in between first node
            curr1 -> next = curr2;
            next2 = curr2 -> next; // keeping the track of further second linked list 
            curr2 -> next = next1;

            
            //updating pointers

            curr1 = curr2;
            //next1 = curr1 -> next;
            curr2 = next2;
        }

        else {
            //changing the window for the future checking
            curr1 = next1;
            next1 = next1 -> next;
            
            //edge case handling... ki aage jate time next1 NULL to nhi ho rha hai n ?
            if(next1 == NULL) {
                curr1 -> next = curr2;
                return n1head;
            }
        }
    }
}

//2nd Function to merge two sorted linked list 
node* mergelist2(node* n1head, node* n2head) {
    if(n1head == NULL) {
        return n2head;
    }
    if(n2head == NULL) {
        return n1head;
    }

    node* ans = new node(-1);
    node* temp = ans;

    while(n1head != NULL || n2head != NULL) {
        if(n1head -> data <= n2head -> data) {
            temp -> next = n1head;
            temp = n1head;
            n1head = n1head -> next;
        }

        else {
            temp -> next = n2head;
            temp = n2head;
            n2head = n2head -> next;
        }

        while(n1head != NULL) {
            temp -> next = n1head;
            temp = n1head;
            n1head = n1head -> next;
        }

        while(n2head != NULL) {
            temp -> next = n2head;
            temp = n2head;
            n2head = n2head -> next;
        }
    }
    ans = ans -> next;
    return ans;
}


node* merge(node* &n1head, node* &n2head) {
    if(n1head == NULL ) {
        return n2head;
    }

    else if(n2head == NULL) {
        return n1head;
    }

    if(n2head -> data >= n1head -> data) {
        mergeList1(n1head, n2head);
        return n1head;
    }

    else {
        mergeList1(n2head,n1head);
        return n2head;
    }
}


 

int main()
{
    node *n1 = new node(3);
    node *n1head = n1;
    node *n1tail = n1;

    insertAtTail(n1tail, 3);
    insertAtTail(n1tail, 5);

    cout << "PRINTING FIRST LIST" << endl;
    print(n1head);

    node *n2 = new node(2);
    node *n2head = n2;
    node *n2tail = n2;

    insertAtTail(n2tail, 4);
    insertAtTail(n2tail, 6);
    cout << endl << "PRINTING SECOND LIST" << endl;
    print(n2head);

   
    node* temp = mergelist2(n1head, n2head);

    cout << endl << "Printing the linked list after merging in sorted order" << endl;
    
    print(temp);


}


