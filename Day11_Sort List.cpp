class Solution {
public:
    void solve(ListNode* head, int idx, vector<int>&temp){
        if(head == NULL)return;
        head->val = temp[idx];
        solve(head->next,idx+1,temp);
    }
    ListNode* sortList(ListNode* head) {
        vector<int>temp;
        ListNode* curr = head;
        while(curr!=NULL){
            int x = curr->val;
            temp.push_back(x);
            curr = curr->next;
        }
        sort(temp.begin(),temp.end());
        solve(head,0,temp);
        return head;
    }
};
