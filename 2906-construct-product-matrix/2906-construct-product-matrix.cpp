#define mod 12345
#define ll long long int
class Solution 
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>prefix(n*m, 1);
        vector<int>suffix(n*m, 1);

        for(int i=1;i<prefix.size();i++)
        {
            int mid = i-1;
            int row = mid/m;
            int col = mid%m;
            int value = grid[row][col];
            prefix[i] = ((ll)(prefix[i-1]%mod)*(ll)(value%mod));
        }

        for(int i=suffix.size()-2;i>=0;i--)
        {
            int mid = i+1;
            int row = mid/m;
            int col = mid%m;
            int value = grid[row][col];
            suffix[i] = ((ll)(suffix[i+1]%mod)*(ll)(value%mod));
        }

        int temp = 0;

        vector<vector<int>>result(n, vector<int>(m, 1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                result[i][j] = ((ll)(prefix[temp]) * (ll)(suffix[temp]))%mod;
                temp++;
            }
        }
        return result;
    }
};