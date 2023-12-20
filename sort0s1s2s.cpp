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

void sortLinkedlist(node *&head, node *&tail)
{
    //In this logic we are changing OR manupulating the data of a node
    // What if interviwer will say that you can't play with the original data of the node ,, in 2nd Approach ww have solved this case
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            countZero++;
        }

        else if (temp->data == 1)
        {
            countOne++;
        }

        else if (temp->data == 2)
        {
            countTwo++;
        }

        temp = temp->next;
    }
    // cout << countZero << " " << countOne << " " << countTwo << " ";

    node *temp2 = head;

    while (temp2 != NULL)
    {
        if (temp2->data != 0 && countZero != 0) 
        {
            temp2->data = 0;
            countZero--;
        }

        else if (temp2->data != 1 && countOne != 0)
        {
            temp2->data = 1;
            countOne--;
        }

        else if (temp2->data != 2 && countTwo != 0)
        {
            temp2->data = 2;
            countTwo--;
        }

        temp2 = temp2 -> next;
    }

    print(head);


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

    sortLinkedlist(head, tail);
}