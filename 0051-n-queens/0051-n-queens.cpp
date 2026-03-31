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

    void solve(int row, int n, vector<vector<string>>&result, vector<string>&path, int cnt)
    {
        if(row == n && cnt == n)
        {
            result.push_back(path);
            return;
        }
        for(int i=row;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(is_valid(path, i, j))
                {
                    path[i][j]='Q';
                    solve(i+1, n, result, path, cnt+1);
                    path[i][j]='.';
                }
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
        int cnt = 0;
        solve(0, n, result, path, cnt);
        return result;
    }
};