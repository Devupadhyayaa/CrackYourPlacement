class Solution
{
    public:
    vector<int>temp;
    void travel(Node *root){
        if(root==NULL)return ;
        travel(root->left);
        temp.push_back(root->data);
        travel(root->right);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        travel(root);
        Node*head = new Node(temp[0]);
        if(temp.size()==1)return head;
        Node*curr = head;
        Node*pre = NULL; Node*next ;
        for(int i = 0;i<temp.size()-1;i++){
            next = new Node(temp[i+1]);
            curr->left = pre;
            curr->right = next;
            pre = curr;
            curr = next;
        }
        curr->left = pre;
        curr->right = NULL;
        return head;
        
    }
};
