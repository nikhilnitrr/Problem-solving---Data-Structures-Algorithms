class Solution 
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0;
        int j = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int k = i;
                int l = j;
                while(k<n-1 && l<m-1)
                {
                    if(matrix[k][l] == matrix[k+1][l+1])
                    {
                        k+=1;
                        l+=1;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};