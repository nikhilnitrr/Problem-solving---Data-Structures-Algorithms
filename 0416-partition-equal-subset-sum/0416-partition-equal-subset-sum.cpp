class Solution 
{
public:

    bool solve(vector<int>&nums, int n, int target, vector<vector<int>>&dp)
    {
        if(target < 0)
        {
            return false;
        }
        if(target == 0)
        {
            return true;
        }
        if(n<=0)
        {
            return false;
        }

        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }

        bool not_take = solve(nums, n-1, target, dp);

        bool take = false;

        if(nums[n-1] <= target)
        {
            take = solve(nums, n-1, target-nums[n-1], dp);
        }

        return dp[n][target] = take || not_take;
    }

    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 !=0) return false;
        int target = sum/2;
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(nums, n, target, dp);
    }
};