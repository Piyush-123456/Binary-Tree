class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root == p) {
            return p;
        }
        if (root == q) {
            return q;
        }
        TreeNode* leftree = lowestCommonAncestor(root->left, p, q);
        TreeNode* righttree = lowestCommonAncestor(root->right, p, q);
        if (leftree == NULL && righttree != NULL) {
            return righttree;
        }
        if (leftree != NULL && righttree == NULL) {
            return leftree;
        }
        if (leftree == NULL && righttree == NULL) {
            return NULL;
        } else {
            return root;
        }
    }
};
