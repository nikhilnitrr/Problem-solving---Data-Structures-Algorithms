class Solution 
{
public:

    bool is_valid_window(int j, int i, int k, int max_freq)
    {
        int window_size = j-i+1;
        if(window_size - max_freq <= k)
        {
            return true;
        }
        return false;
    }

    int characterReplacement(string s, int k) 
    {
        int result = INT_MIN;
        int  i = 0;
        unordered_map<char, int>um;
        int max_freq = 0;
        for(int j=0;j<s.length();j++)
        {
            um[s[j]]++;
            max_freq = max(max_freq, um[s[j]]);
            while(!is_valid_window(j, i, k, max_freq))
            {
                um[s[i]]--;
                i++;
            }
            result = max(result, (j-i+1));
        }
        return result;
    }
};
