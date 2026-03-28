class Solution 
{
public:
    int lengthOfLongestSubstring(string str) 
    {
        int n = str.length();
        unordered_map<char, int>um;
        int result = 0;

        int i = 0;
        for(int j=0;j<n;j++)
        {
            if(um.find(str[j])!=um.end())
            {
                if(um[str[j]] + 1 > i)
                {
                    i = um[str[j]]+1;
                }
            }
            um[str[j]]=j;
            result = max(result, j-i+1);
        }
        return result;
    }
};
