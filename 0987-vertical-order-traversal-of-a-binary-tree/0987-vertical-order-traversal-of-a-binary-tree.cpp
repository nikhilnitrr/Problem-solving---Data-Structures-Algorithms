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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        vector<vector<int>>result;
        queue<pair<TreeNode*, pair<int, int>>>q;
        map<int, vector<pair<int, int>>>mp;
        q.push({root, {0, 0}});

        while(!q.empty())
        {
            pair<TreeNode*, pair<int, int>>p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int h_level = p.second.first;
            int v_level = p.second.second;

            mp[v_level].push_back({h_level, node->val});

            if(node->left)
            {
                q.push({node->left, {h_level+1, v_level-1}});
            }
            if(node->right)
            {
                q.push({node->right, {h_level+1, v_level+1}});
            }
        }
        for(auto x : mp)
        {
            sort(x.second.begin(), x.second.end());
            vector<int>temp;
            for(auto y : x.second)
            {
                temp.push_back(y.second);
            }
            result.push_back(temp);
        }
        return result;
    }
};