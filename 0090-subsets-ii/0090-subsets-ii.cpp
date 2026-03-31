class Solution 
{
public:
    void solve(int pos, vector<int>&nums, int n, vector<int>&path, vector<vector<int>>&result)
    {
        if(find(result.begin(), result.end(), path) == result.end())
        {
            result.push_back(path);
        }
        for(int i=pos;i<n;i++)
        {
            path.push_back(nums[i]);
            solve(i+1, nums, n, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>path;
        sort(nums.begin(), nums.end());
        solve(0, nums, n, path, result);
        return result;
    }
};