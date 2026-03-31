class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<=1)
        {
            return;
        }
        int indx1 = -1;
        int indx2 = -1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                indx1 = i;
                break;
            }
        }
        if(indx1 == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i] > nums[indx1])
            {
                indx2 = i;
                break;
            }
        }
        swap(nums[indx1], nums[indx2]);
        reverse(nums.begin()+indx1+1, nums.end());
    }
};