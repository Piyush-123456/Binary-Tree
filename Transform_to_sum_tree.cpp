class Solution {
  public:
  
    int solve(Node* &root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        int leftsubtree = solve(root->left);
        int rightsubtree = solve(root->right);
        int tempdata = root->data;
        root->data = leftsubtree + rightsubtree;
        return tempdata + root->data;
    }
    void toSumTree(Node *node)
    {
         solve(node);
    }
};
