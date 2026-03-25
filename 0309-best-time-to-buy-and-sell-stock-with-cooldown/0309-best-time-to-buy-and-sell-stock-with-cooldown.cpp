class Solution 
{
public:

    int solve(int i, vector<int>&prices, int n, bool holding, map<pair<int, bool>, int>&dp)
    {
        if(dp.find({i, holding})!=dp.end())
        {
            return dp[{i, holding}];
        }
        if(i>=n)
        {
            return dp[{i, holding}] = 0;
        }
        int max_profit = INT_MIN;
        if(holding)
        {
            int temp1 = prices[i]+solve(i+2, prices, n, false, dp); // sell on ith day
            int temp2 = solve(i+1, prices, n, true, dp); //donot sell on ith day
            max_profit = max(max_profit, max(temp1, temp2));
        }
        else
        {
            int temp1 = -prices[i]+solve(i+1, prices, n, true, dp); // buy on ith day
            int temp2 = solve(i+1, prices, n, false, dp); // don't buy on ith day
            max_profit = max(max_profit, max(temp1, temp2));
        }
        return dp[{i, holding}] = max_profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        map<pair<int, bool>, int>dp;
        return solve(0, prices, n, false, dp);
    }
};
