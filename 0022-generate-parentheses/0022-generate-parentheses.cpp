class Solution 
{
public:

    bool is_valid(string &str)
    {
        int n = str.length();
        int open_cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(')
            {
                open_cnt++;
            }
            if(str[i]==')')
            {
                open_cnt--;
            }

            if(open_cnt < 0)
            {
                return false;
            }
        }
        return open_cnt == 0;
    }

    void solve(string &path, vector<string>&result, int &n, string &nums)
    {
        if(path.length() > 2*n)
        {
            return;
        }
        if(path.length() == 2*n && is_valid(path))
        {
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            solve(path, result, n, nums);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string>result;
        string path;
        string nums="()";
        solve(path, result, n, nums);
        return result;
    }
};