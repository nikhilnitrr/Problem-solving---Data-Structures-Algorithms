class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0;
        while(i<n)
        {
            if(nums[i] == n)
            {
                i++;
            }
            else
            {
                int correct_index = nums[i];
                if(nums[i] != nums[correct_index])
                {
                    swap(nums[i], nums[correct_index]);
                }
                else
                {
                    i++;
                }
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(i!=nums[i])
            {
                ans = i;
                break;
            }
        }
        return ans == -1 ? n : ans;
    }
};
