class Solution 
{
public:

    void solve(int pos, vector<int>&nums, int n, vector<int>&path, vector<vector<int>>&result)
    {
        result.push_back(path);
        for(int i=pos;i<n;i++)
        {
            path.push_back(nums[i]);
            solve(i+1, nums, n, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>path;
        solve(0, nums, n, path, result);
        return result;
    }
};