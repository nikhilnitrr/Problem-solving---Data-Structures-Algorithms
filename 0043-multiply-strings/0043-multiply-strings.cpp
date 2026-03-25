class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        if(num1=="0" || num2=="0") return "0";
        int n = num1.length();
        int m = num2.length();

        string result = "";
        vector<int>temp(n+m, 0);

        for(int j=n-1;j>=0;j--)
        {
            int a = (int)(num1[j]-'0');
            for(int i=m-1;i>=0;i--)
            { 
                int b = (int)(num2[i]-'0');
                int mul = (a*b);
                int sum = mul + temp[i+j+1];
                temp[i+j+1] = sum%10;
                temp[i+j] += sum/10;
            }
        }

        for(int i=0;i<temp.size();i++)
        {
            result+=to_string(temp[i]);
        }
        return result[0]=='0' ? result.substr(1) : result;
    }
};