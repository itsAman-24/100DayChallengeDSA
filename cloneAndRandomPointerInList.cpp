/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
   void insertAtTail(Node* &cloneHead , Node* &cloneTail, int data) {
       Node* temp = new Node(data);
       if(cloneHead == NULL) {
           cloneHead = temp;
           cloneTail = temp;
        }

        else {
            cloneTail -> next = temp;
            cloneTail = temp;
        }
   } 

public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        //Creating clone from old list
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead ,cloneTail,temp->val);
            temp = temp -> next;
        }
        //Creating a map
        unordered_map<Node*,Node*> oldToNewNode;

        Node* oldNode = head;
        Node* cloneNode = cloneHead;

        //mapping between the oldNodes and cloneNodes 
        while(oldNode != NULL) {
            oldToNewNode[oldNode] = cloneNode;
            oldNode = oldNode -> next;
            cloneNode = cloneNode -> next;
        }
        //connecting random pointer using map
        oldNode = head;
        cloneNode = cloneHead;

        while(oldNode != NULL) {
            cloneNode -> random = oldToNewNode[oldNode -> random];
            oldNode = oldNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneHead;
    }
};