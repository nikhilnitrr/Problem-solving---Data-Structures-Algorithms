class Solution 
{
public:

    bool check(string &str, vector<vector<int>>& lcp)
    {
        int n = str.length();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i=0;i<n;i++)
        {
            dp[i][n-1] = (str[i] == str[n-1]) ? 1 : 0;
        }
        for(int j=0;j<n;j++)
        {
            dp[n-1][j] =  (str[n-1] == str[j]) ? 1 : 0;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                if(str[i] == str[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        return dp == lcp;
    }

    string findTheString(vector<vector<int>>& lcp) 
    {
        int n = lcp.size();
        string str(n, '$');
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(lcp[j][i] != 0)
                {
                    str[i] = str[j];
                    break;
                }
            }
            if(str[i]=='$')
            {
                vector<bool>forbidden(26, false);
                for(int j=0;j<i;j++)
                {
                    if(lcp[j][i] == 0)
                    {
                        forbidden[str[j]-'a'] = true;
                    }
                }
                for(int idx=0;idx<26;idx++)
                {
                    if(forbidden[idx]==false)
                    {
                        str[i]= char(idx + 'a');
                        break;
                    }
                }
            }
            if(str[i] == '$')
            {
                return "";
            }
        }
        if(check(str, lcp) == true)
        {
            return str;
        }
        return "";
    }
};