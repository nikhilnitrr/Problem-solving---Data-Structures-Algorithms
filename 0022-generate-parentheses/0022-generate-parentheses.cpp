class Solution 
{
public:
    void solve(string &path, vector<string>&result, int &n, string &nums, int open_cnt)
    {
        if(open_cnt < 0)
        {
            return;
        }
        if(path.length() > 2*n)
        {
            return;
        }
        if(path.length() == 2*n && open_cnt == 0)
        {
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            if(nums[i] == '(')
            {
                solve(path, result, n, nums, open_cnt+1);
            }
            else
            {
                solve(path, result, n, nums, open_cnt-1);
            }
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string>result;
        string path;
        string nums="()";
        int open_cnt = 0;
        solve(path, result, n, nums, open_cnt);
        return result;
    }
};