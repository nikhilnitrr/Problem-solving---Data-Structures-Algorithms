#include<bits/stdc++.h>
int dp[101][101];

class Solution 
{
public:

    bool solve(int i, string s1, int j, string s2, string s3, int n, int m, int l)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==n && j==m && i+j==l)
        {
            return true;
        }
        if(s1[i] == s3[i+j] && s2[j]!=s3[i+j])
        {
            return dp[i][j] = solve(i+1, s1, j, s2, s3, n, m, l);
        }
        else if(s1[i]!=s3[i+j] && s2[j]==s3[i+j])
        {
            return dp[i][j] = solve(i, s1, j+1, s2, s3, n, m, l);
        }
        else if(s1[i]==s3[i+j] && s2[j]==s3[i+j])
        {
            return dp[i][j] = (solve(i+1, s1, j, s2, s3, n, m, l) || solve(i, s1, j+1, s2, s3, n, m, l));
        }
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) 
    {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();

        memset(dp, -1, sizeof(dp));

        if(n+m != l)
        {
            return false;
        }
        return solve(0, s1, 0, s2, s3, n, m, l);
    }
};
