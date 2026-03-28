class Solution 
{
public:
    bool is_valid_window(int end, int start, int max_freq, int k)
    {
        int window_size = end - start + 1;
        if(window_size - max_freq <=k)
        {
            return true;
        }
        return false;
    }

    int characterReplacement(string str, int k) 
    {
        int i = 0;
        int n = str.length();
        int max_freq = 0;
        int result = 0;
        unordered_map<char, int>um;
        for(int j=0;j<n;j++)
        {
            um[str[j]]++;
            max_freq = max(max_freq, um[str[j]]);
            if(is_valid_window(j, i, max_freq, k))
            {
                result = max(result, (j-i+1));
            }
            else
            {
                um[str[i]]--;
                i++;
            }
        }
        return result;
    }
};
