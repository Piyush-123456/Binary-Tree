class Solution {
public:
    void solve(TreeNode* root, int target, vector<vector<int>>& ans,
               vector<int> temp, int sum) {
        if (root == NULL) {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == target) {
                ans.push_back(temp);
            } else {
                return;
            }
        }
        solve(root->left, target, ans, temp, sum);
        solve(root->right, target, ans, temp, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};
