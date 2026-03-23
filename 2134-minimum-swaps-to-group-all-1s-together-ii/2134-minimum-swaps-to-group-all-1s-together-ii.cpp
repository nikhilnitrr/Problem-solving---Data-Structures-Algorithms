class Solution 
{
public:
    int minSwaps(vector<int>& nums) 
    {
        int n = nums.size();
        int total_ones = 0; // will also represent window size
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 1)
            {
                total_ones++;
            }
        }
        int i=0;
        int j=0;
        int curr_ones = 0;
        int max_ones = 0;
        while(j< 2*n)
        {
            if(j-i+1 > total_ones)
            {
                curr_ones-=nums[i%n];
                i++;
            }
            if(nums[j%n] == 1)
            {
                curr_ones++;
            }
            j++;
            max_ones = max(max_ones, curr_ones);
        }

        return total_ones - max_ones;
    }
};