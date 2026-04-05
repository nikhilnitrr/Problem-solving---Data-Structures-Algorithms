class Solution 
{
public:

    bool is_valid(int mid, vector<int>&nums, int m, int k)
    {
        // assume kar ki tu "mid" days k baad garden jaa raha hai
        for(int i=0;i<nums.size();i++)
        {
            int cnt = 0;
            while(i< nums.size() && nums[i] <= mid)
            {
                cnt++;
                if(cnt == k)
                {
                    break;
                }
                i++;
            }
            if(cnt == k)
            {
                m--;
            }
        }
        return m<=0;
    }

    int minDays(vector<int>& nums, int m, int k) 
    {
        int n = nums.size();
        int ans = INT_MAX;
        int low = 1;
        int high = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            high = max(high, nums[i]);
        }
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(is_valid(mid, nums, m, k))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};