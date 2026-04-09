class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n==0)
        {
            return false;
        }
        if(n==1)
        {
            if(nums[0]==0 && k<=1)
            {
                return true;
            }
            if(nums[0]==1 && k==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(nums[0]==0 && nums[1]==0)
        {
            nums[0]=1;
            k--;
        }
        if(nums[n-1]==0 && nums[n-2]==0)
        {
            nums[n-1]=1;
            k--;
        }

        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==0 && nums[i-1]==0 && nums[i+1]==0)
            {
                nums[i]=1;
                k--;
            }
        }
        
        return k<=0;
    }
};