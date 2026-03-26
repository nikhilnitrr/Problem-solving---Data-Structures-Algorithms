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

    void solve(TreeNode* root, int target_sum, ll curr_sum, unordered_map<ll, int>&um, int &cnt)
    {
        if(root == NULL)
        {
            return;
        }
        curr_sum+=(ll)root->val;
        if(curr_sum == target_sum)
        {
            cnt++;
        }
        if(um.find(curr_sum-target_sum)!=um.end())
        {
            cnt+=(um[curr_sum-target_sum]);
        }
        um[curr_sum]++;
        solve(root->left, target_sum, curr_sum, um, cnt);
        solve(root->right, target_sum, curr_sum, um, cnt);
        um[curr_sum]--;
    }

    int pathSum(TreeNode* root, int target_sum) 
    {
        unordered_map<ll, int>um;
        int cnt = 0;
        solve(root, target_sum, 0, um, cnt);
        return cnt;
    }
};