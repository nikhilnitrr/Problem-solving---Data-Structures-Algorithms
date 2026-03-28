class Solution 
{
public:

    bool is_valid(unordered_map<char, int>&um1, unordered_map<char, int>&um2)
    {
        for(auto x : um2)
        {
            char ch = x.first;
            int freq = x.second;

            if(um1.find(ch) == um1.end())
            {
                return false;
            }
            if(um1.find(ch)!=um1.end() && x.second > um1[ch])
            {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) 
    {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int>um1;
        unordered_map<char, int>um2;

        int l_index = -1;
        int r_index = -1;
        int min_len = INT_MAX;
        
        for(int i=0;i<t.length();i++)
        {
            um2[t[i]]++;
        }

        int  i = 0;
        for(int j=0;j<s.length();j++)
        {
            um1[s[j]]++;
            while(is_valid(um1, um2))
            {
                int curr_len = j-i+1;
                if(curr_len < min_len)
                {
                    min_len = curr_len;
                    l_index = i;
                    r_index = j;
                }
                um1[s[i]]--;
                i++;
            }
        }
        if(l_index == -1 || r_index == -1)
        {
            return "";
        }
        return s.substr(l_index, r_index - l_index+1);
    }
};