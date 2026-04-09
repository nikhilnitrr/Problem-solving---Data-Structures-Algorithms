class Solution 
{
public:
    string customSortString(string order, string str) 
    {
        unordered_map<char, int>um1;
        for(int i=0;i<str.length();i++)
        {
            um1[str[i]]++;
        }

        string result="";
        for(int i=0;i<order.length();i++)
        {
            if(um1.find(order[i])!=um1.end())
            {
                int cnt = um1[order[i]];
                while(cnt)
                {
                    result.push_back(order[i]);
                    cnt--;
                }
            }
        }

        unordered_set<char>st;
        for(int i=0;i<order.length();i++)
        {
            st.insert(order[i]);
        }

        for(int i=0;i<str.length();i++)
        {
            if(st.find(str[i])==st.end())
            {
                result.push_back(str[i]);
            }
        }

        return result;
    }
};