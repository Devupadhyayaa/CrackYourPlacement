
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> umap;
        Node* temp = head;
        while(temp){
            umap[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp){
            Node* newNode = umap[temp];
            newNode->next = umap[temp->next];
            newNode->random = umap[temp->random];
            temp = temp->next;
        }
        return umap[head];
    }
};
