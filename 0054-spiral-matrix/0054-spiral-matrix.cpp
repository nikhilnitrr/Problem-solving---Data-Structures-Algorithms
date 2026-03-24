class Solution 
{
public:

    void solve(vector<int>&result, vector<vector<int>>& matrix, int n, int m)
    {
        int row_start = 0;
        int col_start = 0;
        int row_end = n-1;
        int col_end = m-1;

        while(row_start <= row_end && col_start <= col_end)
        {
                if(n >=1)
                {
                    for(int i=col_start;i<=col_end;i++)
                    {
                        result.push_back(matrix[row_start][i]);
                    }
                    row_start++;
                    if(row_start > row_end) break;
                }

                if(m>=1)
                {
                    for(int i=row_start;i<=row_end;i++)
                    {
                        result.push_back(matrix[i][col_end]);
                    }
                    col_end--;
                    if(col_start > col_end)
                    {
                        break;
                    }
                }

                if(n>1)
                {
                    for(int i=col_end;i>=col_start;i--)
                    {
                        result.push_back(matrix[row_end][i]);
                    }
                    row_end--;
                    if(row_start > row_end) break;
                }

                if(m>1)
                {
                    for(int i=row_end;i>=row_start;i--)
                    {
                        result.push_back(matrix[i][col_start]);
                    }
                    col_start++;
                    if(col_start > col_end)
                    {
                        break;
                    }
                }
        }

        
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>result;
        solve(result, matrix, n, m);
        return result;
    }
};
