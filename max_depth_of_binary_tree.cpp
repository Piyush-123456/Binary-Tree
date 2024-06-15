class Solution {
public:
    int solve(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int count = 1;
        while (q.size() > 1) {
            TreeNode* frontnode = q.front();
            q.pop();
            if (frontnode == NULL) {
                count++;
                q.push(NULL);
            } else {
                if (frontnode->left != NULL) {
                    q.push(frontnode->left);
                }
                if (frontnode->right != NULL) {
                    q.push(frontnode->right);
                }
            }
        }
        return count;
    }
    int maxDepth(TreeNode* root) { return solve(root); }
};
