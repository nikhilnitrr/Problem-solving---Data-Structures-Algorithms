/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
public:

    void preorder(TreeNode* root, string &encode)
    {
        if(root == NULL)
        {
            encode.push_back('$');
            return;
        }
        encode+=to_string(root->val)+"#";
        preorder(root->left, encode);
        preorder(root->right, encode);
    }

    string serialize(TreeNode* root) 
    {
        string encode = "";
        preorder(root, encode);
        return encode;
    }

    TreeNode* solve(string &data, int &start, int &end)
    {
        if(start > end)
        {
            return NULL;
        }
        if(data[start] == '$')
        {
            start+=1;
            return NULL;
        }
        string value="";
        int pos = start;
        while(pos <= end && data[pos]!='#')
        {
            value.push_back(data[pos]);
            pos++;
        }
        start=pos+1;
        TreeNode* root = new TreeNode(stoi(value));
        root->left = solve(data, start, end);
        root->right = solve(data, start, end);

        return root;
    }

    TreeNode* deserialize(string &data) 
    {
        int start = 0;
        int end = data.length()-1;
        return solve(data, start, end);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));