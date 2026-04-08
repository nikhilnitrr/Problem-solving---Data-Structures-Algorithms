class Solution 
{
public:

    int solve(int row, int col, vector<vector<int>>&grid, int t_row, int t_col, vector<vector<int>>&dp)
    {
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        if(row > t_row || col > t_col || grid[row][col]==1)
        {
            return dp[row][col] = 0;
        }
        if(row == t_row && col == t_col && grid[row][col]==0)
        {
            return dp[row][col] = 1;
        }
        int total_paths = 0;
        if(row < t_row && grid[row+1][col]==0)
        {
            total_paths+=solve(row+1, col, grid, t_row, t_col, dp);
        }
        if(col < t_col && grid[row][col+1]==0)
        {
            total_paths+=solve(row, col+1, grid, t_row, t_col, dp);
        }
        return dp[row][col] = total_paths;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, grid, n-1, m-1, dp);
    }
};