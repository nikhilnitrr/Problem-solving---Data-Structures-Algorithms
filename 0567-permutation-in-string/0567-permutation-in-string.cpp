class Solution 
{
public:

    bool is_match(vector<int>&a, vector<int>&b)
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string pattern, string text) 
    {
        int n = pattern.length();
        int m = text.length();

        vector<int>arr(26, 0);
        vector<int>brr(26, 0);
        for(int i=0;i<n;i++)
        {
            arr[pattern[i]-'a']++;
        }

        int i = 0;
        int len;
        for(int j=0;j<m;j++)
        {
            brr[text[j]-'a']++;
            len = j-i+1;
            if(len == n)
            {
                if(is_match(arr, brr))
                {
                    return true;
                }
                brr[text[i]-'a']--;
                i++;
            }
        }
        return false;
    }
};
