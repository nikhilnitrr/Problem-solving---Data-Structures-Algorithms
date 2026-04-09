#define ll long long
class Solution 
{
public:

    int solve(int pos, int k, vector<int>&prices, int cnt, bool holding, vector<vector<vector<int>>>&dp)
    {
        if(cnt > k)
        {
            return INT_MIN;
        }
        if(pos == prices.size())
        {
            if(holding)
            {
                return INT_MIN;
            }
            return 0;
        }
        if(dp[pos][cnt][holding]!=-1)
        {
            return dp[pos][cnt][holding];
        }
        ll max_profit = 0;
        for(int i=pos;i<prices.size();i++)
        {
            if(holding)
            {
                max_profit = max(max_profit, (ll)prices[i]+solve(i+1, k, prices, cnt+1, false, dp));
                max_profit = max(max_profit, (ll)solve(i+1, k, prices, cnt, true, dp));
            }
            else
            {
                max_profit = max(max_profit, solve(i+1, k, prices, cnt, true, dp)-(ll)prices[i]);
                max_profit = max(max_profit, (ll)solve(i+1, k, prices, cnt, false, dp));
            }
        }
        return dp[pos][cnt][holding] = max_profit;
    }

    int maxProfit(int k, vector<int>& prices) 
    {
        bool holding = false;
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(0, k, prices, 0, holding, dp);
    }
};