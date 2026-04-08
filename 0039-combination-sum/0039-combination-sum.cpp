class Solution 
{
public:

    void solve(int pos, vector<int>&candidates, int target, vector<vector<int>>&result, vector<int>&path, int curr_sum)
    {
        if(curr_sum > target)
        {
            return;
        }
        if(curr_sum == target)
        {
            result.push_back(path);
            return;
        }
        for(int i=pos;i<candidates.size();i++)
        {
            if(i > pos && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            solve(i, candidates, target, result, path, curr_sum+candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>result;
        vector<int>path;
        solve(0, candidates, target, result, path, 0);
        return result;
    }
};