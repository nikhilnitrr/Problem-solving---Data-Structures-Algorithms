class Solution 
{
public:

    bool solve(int i, int j, int n, int m, string &text, string &pattern)
    {
        if(j==m)
        {
            return true;
        }
        if(i==n)
        {
            return false;
        }
        if(text[i] == pattern[j])
        {
            return solve(i+1, j+1, n, m, text, pattern);
        }
        return solve(i+1, j, n, m, text, pattern);
    }

    bool isSubsequence(string pattern, string text) 
    {
        int n = text.length();
        int m = pattern.length();
        return solve(0, 0, n, m, text, pattern);
    }
};