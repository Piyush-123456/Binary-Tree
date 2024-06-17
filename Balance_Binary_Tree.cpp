class Solution {
public:
    bool balance = true;
    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftree = solve(root->left);
        int rightree = solve(root->right);
        if (balance && abs(leftree - rightree) > 1) {
            balance = false;
        }
        return 1 + max(leftree, rightree);
    }
    bool isBalanced(TreeNode* root) {
        cout << solve(root);
        return balance;
    }
};
