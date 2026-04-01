class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        int res = nums[0];
        int curr = nums[0];
        for(int i=1;i<n;i++)
        {
            curr = max(nums[i], nums[i]+curr);
            res = max(res, curr);
        }
        return res;
    }
};