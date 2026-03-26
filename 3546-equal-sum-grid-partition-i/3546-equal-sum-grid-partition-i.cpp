#define ll long long int
class Solution 
{
public:

    bool is_horizontal_cut(ll total, vector<vector<int>>& grid, unordered_set<ll>&st)
    {
        ll n = grid.size();
        ll m = grid[0].size();
        ll top = 0;

        for(ll i=0;i<n-1;i++)
        {
            for(ll j=0;j<m;j++)
            {
                st.insert(grid[i][j]);
                top+=grid[i][j];
            }
            ll bottom = total - top;
            ll diff = top - bottom;
            if(diff == 0)
            {
                return true;
            }
        }
        st.clear();
        return false;
    }

    void transpose(vector<vector<int>>&grid)
    {
        ll n = grid.size();
        ll m = grid[0].size();

        vector<vector<int>>temp(m, vector<int>(n));

        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                temp[j][i] = grid[i][j];
            }
        }

        grid = temp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        ll n = grid.size();
        ll m = grid[0].size();
        unordered_set<ll>st;

        ll total = 0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                total += grid[i][j];
            }
        }
        if(is_horizontal_cut(total, grid, st))
        {
            return true;
        }
        reverse(grid.begin(), grid.end());
        if(is_horizontal_cut(total, grid, st))
        {
            return true;
        }
        transpose(grid);
        if(is_horizontal_cut(total, grid, st))
        {
            return true;
        }
        reverse(grid.begin(), grid.end());
        if(is_horizontal_cut(total, grid, st))
        {
            return true;
        }
        return false;
    }
};