class Solution 
{
public:

    void solve(string &str, int k, int n)
    {
        while(k > 1)
        {
            int indx1 = -1;
            for(int i=n-2;i>=0;i--)
            {
                if(str[i] < str[i+1])
                {
                    indx1 = i;
                    break;
                }
            }
            if(indx1 == -1)
            {
                reverse(str.begin(), str.end());
                k--;
            }
            else
            {
                int indx2 = -1;
                for(int i=n-1;i>=0;i--)
                {
                    if(str[i] > str[indx1])
                    {
                        indx2 = i;
                        break;
                    }
                }
                swap(str[indx1], str[indx2]);
                reverse(str.begin()+indx1+1, str.end());
                k--;
            }
        }
    }

    string getPermutation(int n, int k) 
    {
        string str="";
        for(int i=1;i<=n;i++)
        {
            str+=to_string(i);
        }
        if(k==0)
        {
            return str;
        }
        solve(str, k, n);
        return str;
    }
};