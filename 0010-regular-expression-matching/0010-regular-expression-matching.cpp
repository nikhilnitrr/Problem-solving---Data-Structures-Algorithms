class Solution 
{
public:

    int dp[21][21];

    bool solve(int i, int j, int n, int m, string text, string pattern)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(j >= m)
        {
            return dp[i][j] = (i >= n);
        }
        
        bool match = i<n && j<m && (text[i]==pattern[j] || pattern[j]=='.');

        if(j < m-1 && pattern[j+1] == '*')
        {
            bool not_take = solve(i, j+2, n, m, text, pattern);
            bool take = match && solve(i+1, j, n, m, text, pattern);
            return dp[i][j] = (take || not_take);
        }
        else
        {
            return dp[i][j] = (match && solve(i+1, j+1, n, m, text, pattern));
        }
    }

    bool isMatch(string text, string pattern) 
    {
        int n = text.length();
        int m = pattern.length();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, n, m, text, pattern);
    }
};
