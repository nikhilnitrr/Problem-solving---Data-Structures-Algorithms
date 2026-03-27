class Solution 
{
public:

    bool update_freq(int src, int dst, vector<int>&freq, vector<int>adj[], int parent)
    {
        if(src==dst)
        {
            freq[dst]++;
            return true;
        }
        for(int u : adj[src])
        {
            if(parent == u)
            {
                continue;
            }
            if(update_freq(u, dst, freq, adj, src))
            {
                freq[src]++;
                return true;
            }
        }
        return false;
    }

    void solve(int root, int parent, vector<int>adj[], vector<pair<int, int>>&dp, vector<int>&price, vector<int>&freq)
    {
        dp[root].first = freq[root] * (price[root]/2);
        dp[root].second = freq[root] * price[root];

        for(int child : adj[root])
        {
            if(child == parent)
            {
                continue;
            }
            solve(child, root, adj, dp, price, freq);
            dp[root].first += (dp[child].second);
            dp[root].second += min(dp[child].first, dp[child].second);
        }
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) 
    {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];

            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        vector<int>freq(n, 0);
        for(int i=0;i<trips.size();i++)
        {
            int src = trips[i][0];
            int dst = trips[i][1];
            bool temp = update_freq(src, dst, freq, adj, -1);
        }

        // Each node will have two costs :
        // 1- If it is halved.
        // 2- If it is not halved.
        vector<pair<int, int>>dp(n, {0, 0});
        solve(0, -1, adj, dp, price, freq);
        return min(dp[0].first, dp[0].second);
    }
};