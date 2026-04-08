class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int zero_count = 0;
        int one_count = 0;
        int two_count = 0;

        for(int i=0;i<n;i++)
        {
           if(nums[i]==0)
           {
            zero_count++;
           }
           else if(nums[i]==1)
           {
            one_count++;
           }
           else
           {
            two_count++;
           }
        }

        int i = 0;
        while(zero_count)
        {
            nums[i] = 0;
            i++;
            zero_count--;
        }
        while(one_count)
        {
            nums[i] = 1;
            i++;
            one_count--;
        }
        while(two_count)
        {
            nums[i] = 2;
            i++;
            two_count--;
        }
    }
};