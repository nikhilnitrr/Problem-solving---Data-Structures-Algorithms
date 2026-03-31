class Solution 
{
public:
    void solve(int pos, vector<int>&nums, int n, vector<vector<int>>&result, vector<int>&path, int curr_sum, int &sum)
    {
        if(curr_sum > sum)
        {
            return;
        }
        if(curr_sum == sum)
        {
            result.push_back(path);
            return;
        }
        for(int i=pos;i<n;i++)
        {
            if(i > pos && nums[i-1] == nums[i]) continue;
            path.push_back(nums[i]);
            solve(i+1, nums, n, result, path, curr_sum+nums[i], sum);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int sum) 
    {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>path;
        sort(nums.begin(), nums.end());
        solve(0, nums, n, result, path, 0, sum);
        return result;
    }
};