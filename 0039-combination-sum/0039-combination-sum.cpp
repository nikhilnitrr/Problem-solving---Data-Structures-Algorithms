class Solution 
{
public:

    void solve(vector<int>&nums, int n, vector<vector<int>>&result, vector<int>&path, int curr_sum, int &sum)
    {
        if(curr_sum > sum)
        {
            return;
        }
        if(curr_sum == sum)
        {
            vector<int>temp = path;
            sort(temp.begin(), temp.end());
            if(find(result.begin(), result.end(), temp) == result.end())
            {
                result.push_back(path);
            }
        }
        for(int i=0;i<n;i++)
        {
            path.push_back(nums[i]);
            solve(nums, n, result, path, curr_sum+nums[i], sum);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int sum) 
    {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>path;
        int curr_sum = 0;
        sort(nums.begin(), nums.end());
        solve(nums, n, result, path, curr_sum, sum);
        return result;
    }
};