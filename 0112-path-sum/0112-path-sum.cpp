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

    void preorder(TreeNode* root, int curr_sum, int target_sum, bool &found)
    {
        if(root == NULL)
        {
            return;
        }
        curr_sum += root->val;
        if(curr_sum == target_sum && root->left==NULL && root->right==NULL)
        {
            found = true;
        }
        preorder(root->left, curr_sum, target_sum, found);
        preorder(root->right, curr_sum, target_sum, found);
    }

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        bool found = false;
        preorder(root, 0, targetSum, found);
        return found;
    }
};