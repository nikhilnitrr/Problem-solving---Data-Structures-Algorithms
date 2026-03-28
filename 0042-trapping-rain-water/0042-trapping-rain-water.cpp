class Solution 
{
public:
    int trap(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int left_max = 0;
        int right_max = 0;
        int result = 0;
        while(i<j)
        {
            if(nums[i] < nums[j])
            {
                left_max = max(left_max, nums[i]);
                result+= (left_max - nums[i]);
                i++;
            }
            else
            {
                right_max = max(right_max, nums[j]);
                result+=(right_max - nums[j]);
                j--;
            }
        }
        return result;
    }
};