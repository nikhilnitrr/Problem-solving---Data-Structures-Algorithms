class Solution 
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>prev = matrix[0];
        for(int i=1;i<n;i++)
        {
            vector<int>curr = matrix[i];
            for(int j=1;j<m;j++)
            {
                if(curr[j]!=prev[j-1])
                {
                    return false;
                }
            }
            prev=curr;
        }
        return true;
    }
};