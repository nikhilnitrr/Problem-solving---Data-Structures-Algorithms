class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        if(num1=="0" || num2=="0")
        {
            return "0";
        }
        int n = num1.length();
        int m = num2.length();
        
        vector<int>result(n+m, 0);

        int i = n-1;
        int j = m-1;

        while(j>=0)
        {
            i=n-1;
            int a = (int)(num2[j]-'0');
            while(i>=0)
            {
                int b = (int)(num1[i]-'0');

                int mul = a*b;

                int sum = mul + result[i+j+1];

                result[i+j+1] = sum%10;
                result[i+j]+=sum/10;
                
                i--;
            }
            j--;

        }
        string ans = "";
        for(int i=0;i<result.size();i++)
        {
            ans+=to_string(result[i]);
        }
        return ans[0]=='0' ? ans.substr(1) : ans;
    }
};
