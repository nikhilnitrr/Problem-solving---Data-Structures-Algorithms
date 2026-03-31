class Solution 
{
public:

    void solve(int pos, int n, int k, vector<int>&path, vector<vector<int>>&result)
    {
        if(path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for(int i=pos;i<=n;i++)
        {
            path.push_back(i);
            solve(i+1, n, k, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>result;
        vector<int>path;
        solve(1, n, k, path, result);
        return result;
    }
};