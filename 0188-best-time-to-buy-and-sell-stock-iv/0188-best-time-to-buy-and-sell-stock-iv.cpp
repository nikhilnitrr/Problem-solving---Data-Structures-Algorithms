#define ll long long
class Solution 
{
public:

    int solve(int pos, int k, vector<int>& prices, int cnt, bool holding,
              vector<vector<vector<int>>>& dp)
    {
        if(cnt > k)
            return -1e9;

        if(pos == prices.size())
            return holding ? -1e9 : 0;

        if(dp[pos][cnt][holding] != -1)
            return dp[pos][cnt][holding];

        int max_profit = 0;

        if(holding)
        {
            // sell
            max_profit = max(max_profit,
                prices[pos] + solve(pos+1, k, prices, cnt+1, false, dp));

            // skip
            max_profit = max(max_profit,
                solve(pos+1, k, prices, cnt, true, dp));
        }
        else
        {
            // buy
            max_profit = max(max_profit,
                solve(pos+1, k, prices, cnt, true, dp) - prices[pos]);

            // skip
            max_profit = max(max_profit,
                solve(pos+1, k, prices, cnt, false, dp));
        }

        return dp[pos][cnt][holding] = max_profit;
    }

    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(0, k, prices, 0, false, dp);
    }
};