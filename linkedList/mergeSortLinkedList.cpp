class Solution {
private:
   ListNode* mergeList(ListNode* &left, ListNode* &right) {
       if(left == NULL) {
           return right;
       }

       if(right == NULL) {
           return left;
       }

       ListNode* ans = new ListNode(-1);
       ListNode* temp = ans;

       while(left != NULL || right != NULL) {
           if(left -> val <= right -> val) {
               temp -> next = left;
               temp = left;
               left = left -> next;
           }

           else {
               temp -> next = right;
               temp = right;
               right = right -> next;
           }

           while(left != NULL) {
               temp -> next = left;
               temp = left;
               left = left -> next;
           }

           while(right != NULL) {
               temp -> next = right;
               temp = right;
               right = right -> next;
           }
       }
       ans = ans -> next;
       return ans;
}

ListNode* findmid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        //Finding midnode 
        ListNode* midnode = findmid(head);

        //Dividing the list into two parts for using merge sort
        ListNode* left = head;
        ListNode* right = midnode -> next;
        midnode -> next = NULL;

        //Sorting the two lists by using recursive function
        left = sortList(left);
        right = sortList(right);

    //Merging the two sorted list by using approach of merge two     sorted lists
        
        ListNode* result = mergeList(left,right);

        return result;
    }
}; 