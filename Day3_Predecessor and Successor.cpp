    public:
    void pre1(Node* root, Node*&pre, int key){
        if(root==NULL)return;
        
        if(root->key<key){
            pre = root;
            pre1(root->right,pre,key);
            return;
        }
        else pre1(root->left,pre,key);
        return;
    }
    
    void suc1(Node* root, Node*&suc, int key){
        if(root==NULL)return;
        
        if(root->key>key){
            suc = root;
            suc1(root->left,suc,key);
            return;
        }
        else suc1(root->right,suc,key);
        return;
    }    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = NULL;
        suc = NULL;
        
        pre1(root,pre,key);
        suc1(root,suc,key);
    }
