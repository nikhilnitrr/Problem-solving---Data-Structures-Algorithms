class Solution 
{
public:

    void solve(vector<int>&nums, int n, vector<int>&path, vector<vector<int>>&result, vector<bool>&visited)
    {
        if(path.size() == n)
        {
            result.push_back(path);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                path.push_back(nums[i]);
                solve(nums, n, path, result, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>path;
        vector<bool>visited(n, false);
        solve(nums, n, path, result, visited);
        return result;
    }
};