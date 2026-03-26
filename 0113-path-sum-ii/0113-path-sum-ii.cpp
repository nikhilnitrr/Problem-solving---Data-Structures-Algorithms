/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:


    void solve(TreeNode* root, int target_sum, vector<int>path, vector<vector<int>>&result)
    {
        if(root == NULL)
        {
            return;
        }
        target_sum-=root->val;
        path.push_back(root->val);
        if(target_sum == 0 && root->left==NULL && root->right==NULL)
        {
            result.push_back(path);
        }
        solve(root->left, target_sum, path, result);
        solve(root->right, target_sum, path, result);
    }

    vector<vector<int>> pathSum(TreeNode* root, int target_sum) 
    {
        vector<vector<int>>result;
        vector<int>path;
        solve(root, target_sum, path, result);
        return result;
    }
};