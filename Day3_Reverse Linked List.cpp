class Solution {
public:
    ListNode* reverseList(ListNode *head, ListNode *nextNode = NULL, ListNode *prevNode = NULL) {
        if(head){
           return reverseList(head->next, (head->next = prevNode, nextNode), head);
        }
        return prevNode;
    }
};
