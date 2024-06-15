class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lefttree = height(root->left);
        int righttree = height(root->right);
        return 1 + max(lefttree, righttree);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int diff = abs(leftheight - rightheight);
        bool curr = diff <= 1;
        bool lefttree = isBalanced(root->left);
        bool righttree = isBalanced(root->right);
        if(curr && lefttree && righttree){
            return true;
        }
        else{
            return false;
        }
    }
};
