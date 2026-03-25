// Here, in many scenarios we are waiting at same position in pattern. So, for the base case condition
// we should check exhaustion of pattern first and if it's exhausted then check for text.

#include<bits/stdc++.h>

int dp[21][21];

class Solution 
{
public:

    bool solve(int i, int j, int n, int m, string text, string pattern)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        // Order is very important
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
