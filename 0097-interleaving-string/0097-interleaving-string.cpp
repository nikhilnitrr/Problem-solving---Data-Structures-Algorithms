#include<bits/stdc++.h>
int dp[201][201][201];

class Solution 
{
public:

    bool solve(int i, string s1, int j, string s2, int k, string s3, int n, int m, int l)
    {
        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        if(i==n && j==m && k==l)
        {
            return true;
        }
        if(s1[i] == s3[k] && s2[j]!=s3[k])
        {
            return dp[i][j][k] = solve(i+1, s1, j, s2, k+1, s3, n, m, l);
        }
        else if(s1[i]!=s3[k] && s2[j]==s3[k])
        {
            return dp[i][j][k] = solve(i, s1, j+1, s2, k+1, s3, n, m, l);
        }
        else if(s1[i]==s3[k] && s2[j]==s3[k])
        {
            return dp[i][j][k] = (solve(i+1, s1, j, s2, k+1, s3, n, m, l) || solve(i, s1, j+1, s2, k+1, s3, n, m, l));
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
        return solve(0, s1, 0, s2, 0, s3, n, m, l);
    }
};
