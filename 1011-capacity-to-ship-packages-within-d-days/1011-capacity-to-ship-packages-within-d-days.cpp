class Solution 
{
public:

    bool is_valid(int k, vector<int>&weights, int days)
    {
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<weights.size();i++)
        {
            if(sum+weights[i] <=k)
            {
                sum = sum + weights[i];
            }
            else
            {
                cnt++;
                sum=weights[i]; // is weight to agle din bhejunga
                if(cnt > days)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();
        int ans = INT_MAX;
        int low=weights[0];
        for(int i=1;i<n;i++)
        {
            low=max(low, weights[i]);
        }
        int high=0;
        for(int i=0;i<n;i++)
        {
            high+=weights[i];
        }
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(is_valid(mid, weights, days))
            {
                ans = mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};