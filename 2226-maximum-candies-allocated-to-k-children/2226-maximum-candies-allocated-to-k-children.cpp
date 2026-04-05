#define ll long long
class Solution 
{
public:

    bool is_valid(int mid, vector<int>&candies, ll k)
    {
        // ek bacche ko 2 pile se candies nhi mil sakta
        // lekin ek hi pile ko bahut baccho ko diya jaa sakta hai
        ll cnt = 0;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i] < mid)
            {
                continue;
            }
            else
            {
                cnt+= ((ll)candies[i]/(ll)mid);
            }
        }
        if(cnt >= k)
        {
            return true;
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) 
    {
        int n = candies.size();
        int ans = 0;
        int low = 1;
        int high=candies[0];
        for(int i=1;i<n;i++)
        {
            high = max(high, candies[i]);
        }
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(is_valid(mid, candies, k))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;   
    }
};