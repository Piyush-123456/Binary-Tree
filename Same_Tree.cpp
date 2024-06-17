class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if(p->val==q->val){
            return solve(p->left, q->left) && solve(p->right, q->right);
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) { 
      return solve(p, q);
    }
};
