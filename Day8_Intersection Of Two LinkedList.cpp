/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node = headA;
        unordered_map<ListNode*,int>um;
        while(node!=NULL){
            um[node]++;
            node = node->next;
        }
        node = headB;
        while(node!=NULL){
            if(um.count(node))return node;
            node = node->next;
        }
        return NULL;
    }
};
