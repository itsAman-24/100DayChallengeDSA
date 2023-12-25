#include <iostream> 
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int d) {
        this -> data = d;
        this -> next = NULL;
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
    node* temp;
    temp = head;

    while(temp != NULL) {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}

int getlength(node* &head) {
    if(head == NULL) {
        return 0;
    }
    
    
    return 1 + getlength(head -> next);
  
}

node* midNode(node* &head) {

    if(head ==NULL) {
        return head;
    }

    else {
        int length = getlength(head);
        int ans = (length/2);
        int count = 0;
        node* temp = head;

        while(count < ans) {
            temp = temp -> next;
            count++;
         }

        cout << temp -> data << endl;
        return temp;
        
    }
    
}
/*We are using this two pointers approach (((Floyd’s cycle finding algorithm or Hare-Tortoise algorithm))) in which fast pointer will jump two steps and the slow will jump one step in each round 
  and when fast will reach the NUll (means ending of linkedlist) then the slow pointer will be pointing to the center of the list 
  (middle node)   [When fast will complete the list traversal slow will be at half of the list as it just jumps one step while fast
  jumps two steps] */


node* middleNode(node* head) {           // optimized function with double pointers approach
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    if(head -> next -> next == NULL) {
        return head -> next;
    }

    node* slow = head;            // first pointer which jump only one step
    node* fast = head -> next;    // second pointer which jump two steps

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

    }

    cout << slow -> data << endl;
    return slow;

}


int main() {
    node* newnode = new node(0);
    node* head = newnode;
    node* tail = newnode;
    insertAtHead(head,10);
    insertAtHead(head,11);
    insertAtHead(head,12);

    insertAtTail(tail,14);
    insertAtTail(tail,15);
    insertAtTail(tail,16);
    insertAtTail(tail,17);
    
    cout << "Your LinkedList is:" << endl;
    print(head);

    cout << endl << "Length of linkedList is : " << getlength(head) << endl;

    cout << "Mid node by bruteforce function  is: " << " ";
    midNode(head);

    cout << "Mid node from optimized function is: " << " ";
    middleNode(head);





}