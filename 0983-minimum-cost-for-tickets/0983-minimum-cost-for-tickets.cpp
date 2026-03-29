class Solution 
{
public:

    int solve(int i, vector<int>&days, int n, vector<int>&costs, vector<int>&dp)
    {
        if(i >= n)
        {
            return 0;
        }

        if(dp[i] !=-1)
        {
            return dp[i];
        }

        int cost1 = costs[0] + solve(i+1, days, n, costs, dp);

        int j = i;
        int k = i;

        while(j < n && days[j] < days[i]+7)
        {
            j++;
        }

        while(k < n && days[k] < days[i]+30)
        {
            k++;
        }

        int cost2 = costs[1] + solve(j, days, n, costs, dp);

        int cost3 = costs[2] + solve(k, days, n, costs, dp);

        return dp[i] = min(cost1, min(cost2, cost3));

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n = days.size();
        vector<int>dp(n+1, -1);
        return solve(0, days, n, costs, dp);
    }
};