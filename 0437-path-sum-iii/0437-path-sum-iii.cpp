#define ll long long int
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

    void solve(TreeNode* root, ll target_sum, int &cnt)
    {
        if(root == NULL)
        {
            return;
        }
        target_sum -= (ll)root->val;
        if(target_sum == 0)
        {
            cnt++;
        }
        solve(root->left, target_sum, cnt);
        solve(root->right, target_sum, cnt);
    }

    void inorder(TreeNode* root, int target_sum, int &cnt)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left, target_sum, cnt);
        solve(root, target_sum, cnt);
        inorder(root->right, target_sum, cnt);
    }

    int pathSum(TreeNode* root, int target_sum) 
    {
        int cnt = 0;
        inorder(root, target_sum, cnt);
        return cnt;
    }
};