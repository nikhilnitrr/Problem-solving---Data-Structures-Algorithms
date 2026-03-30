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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>result;
        if(root == NULL)
        {
            return result;
        }
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});

        while(!q.empty())
        {
            int s = q.size();
            pair<TreeNode*, int>p = q.front();
            int level = p.second;
            vector<int>temp;
            // if(level % 2 == 0)
            // {
                for(int i=0;i<s;i++)
                {
                    pair<TreeNode*, int> x = q.front();
                    q.pop();
                    temp.push_back(x.first->val);
                    if(x.first->left)
                    {
                        q.push({x.first->left, x.second+1});
                    }
                    if(x.first->right)
                    {
                        q.push({x.first->right, x.second+1});
                    }
                }
                if(level % 2 == 0)
                {
                    result.push_back(temp);
                }
                else
                {
                    reverse(temp.begin(), temp.end());
                    result.push_back(temp);
                }
            // }
        }
        return result;
    }
};