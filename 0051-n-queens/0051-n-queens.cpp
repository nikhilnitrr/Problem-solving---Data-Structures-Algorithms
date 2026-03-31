class Solution 
{
public:

    bool is_valid(vector<string>&path, int row, int col)
    {
        for(int i=0;i<path.size();i++)
        {
            if(path[i][col] == 'Q')
            {
                return false;
            }
        }

        // top right diagonal
        int i = row;
        int j = col;

        while(i>=0 && j>=0)
        {
            if(path[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }


        // top left diagonal
        i = row;
        j = col;
        while(i>=0 && j<path.size())
        {
            if(path[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }

    void solve(int row, int n, vector<vector<string>>&result, vector<string>&path)
    {
        if(row == n)
        {
            result.push_back(path);
            return;
        }
            for(int col=0;col<n;col++)
            {
                if(is_valid(path, row, col))
                {
                    path[row][col]='Q';
                    solve(row+1, n, result, path);
                    path[row][col]='.';
                }
            }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>result;
        vector<string>path;
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=0;j<n;j++)
            {
                temp.push_back('.');
            }
            path.push_back(temp);
        }
        solve(0, n, result, path);
        return result;
    }
};