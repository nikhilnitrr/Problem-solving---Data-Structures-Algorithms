class Solution 
{
public:

    bool is_valid(char c2, char c1)
    {
        if((c1=='(' && c2 == ')') || (c1=='{' && c2 =='}') || (c1=='[' && c2 ==']'))
        {
            return true;
        }
        return false;
    }

    bool isValid(string str) 
    {
        int n = str.length();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                st.push(str[i]);
            }
            else if(!st.empty() && is_valid(str[i], st.top()))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();  
    }
};

// Time complexity : O(N)
// Space complexity : O(N)
