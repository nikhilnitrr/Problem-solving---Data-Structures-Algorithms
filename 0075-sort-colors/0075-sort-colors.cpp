class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==0)
            {
                swap(nums[mid], nums[low]);
                low++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};