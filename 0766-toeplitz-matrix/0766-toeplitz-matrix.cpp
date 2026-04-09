class Solution 
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_map<int, int>diagonal;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int key = i-j;
                if(diagonal.find(key)==diagonal.end())
                {
                    diagonal[key]=matrix[i][j];
                }
                else
                {
                    if(diagonal[key]!=matrix[i][j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};