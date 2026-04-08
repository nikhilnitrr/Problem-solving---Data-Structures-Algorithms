class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        int i = 0;
        while(i<=high)
        {
            if(nums[i]==0)
            {
                swap(nums[i], nums[low]);
                low++;
                i++;
            }
            else if(nums[i]==2)
            {
                swap(nums[i], nums[high]);
                high--;
            }
            else
            {
                i++;
            }
        }
    }
};