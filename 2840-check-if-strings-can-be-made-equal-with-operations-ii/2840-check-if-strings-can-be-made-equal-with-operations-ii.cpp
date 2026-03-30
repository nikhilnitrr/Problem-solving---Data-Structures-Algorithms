class Solution 
{
public:
    bool checkStrings(string s1, string s2) 
    {
        if(s1 == s2)
        {
            return true;
        }
        unordered_map<int, vector<char>>um1, um2;   
        int n = s1.length();
        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                um1[0].push_back(s1[i]);
                um2[0].push_back(s2[i]);
            }
            else
            {
                um1[1].push_back(s1[i]);
                um2[1].push_back(s2[i]);
            }
        }
        sort(um1[0].begin(), um1[0].end());
        sort(um1[1].begin(), um1[1].end());
        sort(um2[0].begin(), um2[0].end());
        sort(um2[1].begin(), um2[1].end());
        if(um1[0] == um2[0] && um1[1] == um2[1])
        {
            return true;
        }
        return false;
    }
};