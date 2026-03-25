#define ll long long int
class Solution 
{
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<ll>row_sum(n, 0);
        vector<ll>col_sum(m, 0);

        for(int i=0;i<m;i++)
        {
            ll sum = 0;
            for(int j=0;j<n;j++)
            {
                sum+=(ll)grid[j][i];
            }
            col_sum[i] = sum;
        }

        for(int i=0;i<n;i++)
        {
            ll sum = 0;
            for(int j=0;j<m;j++)
            {
                sum+=(ll)grid[i][j];
            }
            row_sum[i] = sum;
        }

        vector<ll>row_prefix(n, 0);
        vector<ll>row_suffix(n, 0);

        vector<ll>col_prefix(m, 0);
        vector<ll>col_suffix(m, 0);

        row_prefix[0] = row_sum[0];
        for(int i=1;i<n;i++)
        {
            row_prefix[i] = row_prefix[i-1]+row_sum[i];
        }

        row_suffix[n-1] = row_sum[n-1];
        for(int i=n-2;i>=0;i--)
        {
            row_suffix[i] = row_suffix[i+1]+row_sum[i];
        }

        col_prefix[0] = col_sum[0];
        for(int i=1;i<m;i++)
        {
            col_prefix[i] = col_prefix[i-1]+col_sum[i];
        }

        col_suffix[m-1] = col_sum[m-1];
        for(int i=m-2;i>=0;i--)
        {
            col_suffix[i] = col_suffix[i+1]+col_sum[i];
        }

        // check for row
        for(int i=0;i<n-1;i++)
        {
            if(row_prefix[i] == row_suffix[i+1])
            {
                return true;
            }
        }

        // check for col
        for(int i=0;i<m-1;i++)
        {
            if(col_prefix[i] == col_suffix[i+1])
            {
                return true;
            }
        }
        return false;
    }
};