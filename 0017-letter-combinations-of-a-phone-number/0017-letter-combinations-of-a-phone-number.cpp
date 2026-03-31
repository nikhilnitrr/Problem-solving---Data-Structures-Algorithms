class Solution 
{
public:

    void solve(int pos, int n, string &digits, string path, vector<string>&result, unordered_map<char, string>&um)
    {
        if(pos == n && path.length()==n)
        {
            result.push_back(path);
            return;
        }
        for(int i=pos;i<n;i++)
        {
            string temp = um[digits[pos]];
            for(int j=0;j<temp.length();j++)
            {
                path.push_back(temp[j]);
                solve(i+1, n, digits, path, result, um);
                path.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        int n = digits.length();
        vector<string>result;
        string path = "";
        unordered_map<char, string>um;
        um['2'] = "abc";
        um['3'] = "def";
        um['4'] = "ghi";
        um['5'] = "jkl";
        um['6'] = "mno";
        um['7'] = "pqrs";
        um['8'] = "tuv";
        um['9'] = "wxyz";
        solve(0, n, digits, path, result, um);
        return result;
    }
};