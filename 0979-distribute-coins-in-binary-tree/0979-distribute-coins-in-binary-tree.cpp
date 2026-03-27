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

    int solve(TreeNode* root, int &moves)
    {
        if(root == NULL)
        {
            return 0;
        }
        int l = solve(root->left, moves);
        int r = solve(root->right, moves);

        moves+= abs(l)+abs(r);

        int candies = root->val + l + r;

        return candies-1;
    }


    int distributeCoins(TreeNode* root) 
    {
        if(root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        int moves = 0;
        int temp = solve(root, moves);
        return moves;
    }
};