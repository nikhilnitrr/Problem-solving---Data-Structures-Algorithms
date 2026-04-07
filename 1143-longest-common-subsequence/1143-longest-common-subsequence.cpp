class Solution {
public:
    int solve(int n, int m, string &text, string &pattern, vector<vector<int>>&dp)
    {
        for(int i=0;i<=m;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text[i-1] == pattern[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, text1, text2, dp);
    }
};