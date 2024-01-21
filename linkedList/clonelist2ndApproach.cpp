#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Node* next = NULL;
    int data;
    Node* arb = NULL;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> arb = NULL;
    }

private:
    void insert(Node *&head, Node *&tail, int data)
    {

        Node* temp = new Node(data);

        if (head == NULL)
        {

            head = temp;

            tail = temp;
        }

        else
        {

            tail->next = temp;
            tail = temp;
        }
    }

   

public:
    Node* copyList(Node* head) {

        // STEP 1 creating clone list

    Node* cloneHead = NULL;

    Node* cloneTail = NULL;

    Node* temp = head;

    while (temp != NULL)
    {

        insert(cloneHead, cloneTail, temp->data);

        temp = temp->next;
    }

    // STEP 2 placing clonenodes in betweeen the original nodes

    Node* originalNode = head;

    Node* cloneNode = cloneHead;

    // Node* c = NULL;

    while (originalNode != NULL && cloneNode != NULL)
    {

        Node* c = originalNode->next;

        originalNode -> next = cloneNode;

        originalNode = c;

        // same for clone node

        c = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = c;
    }



// STEP 3 Placing random pointer

temp = head;

while (temp != NULL)
{

    if (temp->next != NULL)
    {

        // we can use tertiary expression to write below if else

        //? this sign is used for true condition //: this is used for false condition

        temp->next -> arb = temp -> arb ? temp -> arb->next : temp->arb;

        // if (temp->arb != NULL)
        // {

        //     temp->next->arb = temp->arb->next;

        // }

        //     else
        //     {

        //         temp->next->arb = temp->arb;
        //     }

            temp = temp->next->next; // help to reach the second node of original List
        }
}

        // STEP 4 Reversing STEP 2

        originalNode = head;

        cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {

            originalNode->next = cloneNode->next;

            originalNode = originalNode->next;

            // same for cloneNodes but check if originalNode currently equal to MILL or not

            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }

            cloneNode = cloneNode->next;
        }
        
        // STEP 5 Returning the head
        return cloneHead;
    }

   
};