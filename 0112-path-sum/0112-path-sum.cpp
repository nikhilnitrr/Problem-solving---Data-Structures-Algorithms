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

    bool preorder(TreeNode* root, int curr_sum, int target_sum)
    {
        if(root == NULL)
        {
            return false;
        }
        curr_sum += root->val;
        if(curr_sum == target_sum && root->left==NULL && root->right==NULL)
        {
            return true;
        }
        return preorder(root->left, curr_sum, target_sum) || preorder(root->right, curr_sum, target_sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return preorder(root, 0, targetSum);
    }
};