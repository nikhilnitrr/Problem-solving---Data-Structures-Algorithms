class Solution 
{
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) 
    {
        vector<vector<int>>rank(n, vector<int>(n));
        for(int i=0;i<preferences.size();i++)
        {
            for(int j=0;j<preferences[i].size();j++)
            {
                rank[i][preferences[i][j]]=j;
            }
        }

        unordered_map<int, int>partner;
        for(int i=0;i<pairs.size();i++)
        {
            int x = pairs[i][0];
            int y = pairs[i][1];

            partner[x]=y;
            partner[y]=x;
        }

        int result = 0;
        for(int x=0;x<n;x++)
        {
            int y = partner[x];
            for(int u : preferences[x])
            {
                if(u==y)
                {
                    break;
                }
                int v = partner[u];
                if((rank[x][u] < rank[x][y]) && (rank[u][x] < rank[u][v]))
                {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};