#define mod 1000000007
#define ll long long
class Solution 
{
public:
    int maxProductPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<pair<ll, ll>>>dp(n, vector<pair<ll, ll>>(m, {LLONG_MIN, LLONG_MAX}));

        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int i=1;i<m;i++)
        {
            dp[0][i].first = max((ll)grid[0][i] * dp[0][i-1].first, (ll)grid[0][i] * dp[0][i-1].second);
            dp[0][i].second = min((ll)grid[0][i] * dp[0][i-1].first, (ll)grid[0][i] * dp[0][i-1].second);
        }

        for(int i=1;i<n;i++)
        {
            dp[i][0].first = max((ll)grid[i][0] * dp[i-1][0].first, (ll)grid[i][0] * dp[i-1][0].second);
            dp[i][0].second = min((ll)grid[i][0] * dp[i-1][0].first, (ll)grid[i][0] * dp[i-1][0].second);
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j].first = max(max((ll)grid[i][j]*dp[i-1][j].first, (ll)grid[i][j]*dp[i-1][j].second), max((ll)grid[i][j]*dp[i][j-1].first, (ll)grid[i][j]*dp[i][j-1].second));
                dp[i][j].second = min(min((ll)grid[i][j]*dp[i-1][j].first, (ll)grid[i][j]*dp[i-1][j].second), min((ll)grid[i][j]*dp[i][j-1].first, (ll)grid[i][j]*dp[i][j-1].second));
            }
        }
        ll ans = dp[n-1][m-1].first;
        if(ans < 0) return -1;
        return ans%mod;
    }
};