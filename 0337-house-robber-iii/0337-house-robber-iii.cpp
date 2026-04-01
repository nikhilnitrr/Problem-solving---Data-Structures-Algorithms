/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, unordered_map<TreeNode*, pair<int, int>>& dp) {
        if (root == NULL) {
            dp[root] = {0, 0};
            return;
        }

        solve(root->left, dp);
        solve(root->right, dp);

        dp[root].first =
            root->val + dp[root->left].second + dp[root->right].second;
        dp[root].second = max(dp[root->left].first, dp[root->left].second) +
                          max(dp[root->right].first, dp[root->right].second);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> dp; // rob, not_rob
        solve(root, dp);
        return max(dp[root].first, dp[root].second);
    }
};