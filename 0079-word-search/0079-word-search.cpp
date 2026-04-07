int row[] = {-1, 0, 1, 0};
int col[] = {0, -1, 0, 1};

class Solution 
{
public:
    bool solve(int r, int c, int k, vector<vector<char>>&board, string &word)
    {
        if(k == word.length())
        {
            return true;
        }

        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c]=='#' || board[r][c]!=word[k])
        {
            return false;
        }

        bool is_present = false;

        if(board[r][c] == word[k])
        {
            char ch = word[k];
            board[r][c]='#';
            for(int l=0;l<4;l++)
            {
                int new_row = r + row[l];
                int new_col = c + col[l];
                is_present = is_present || solve(new_row, new_col, k+1, board, word);
            }
            board[r][c]= ch;
        }
        return is_present;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        int k = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(solve(i, j, k, board, word))
                {
                    return true;
                }
            }
        } 

        return false;  
    }
};