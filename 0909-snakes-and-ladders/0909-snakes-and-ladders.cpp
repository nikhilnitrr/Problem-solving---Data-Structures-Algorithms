class Solution 
{
public:

    int solve(int start, int end, vector<int>&arr)
    {
        vector<bool>visited(arr.size(), false);
        queue<pair<int, int>>q;
        q.push({start, 0});
        visited[start] = true;
        while(!q.empty())
        {
            pair<int, int>p=q.front();
            q.pop();
            int pos = p.first;
            int moves = p.second;

            if(pos == end)
            {
                return moves;
            }

            for(int k=1;k<=6;k++)
            {
                int new_pos = pos + k;
                if(new_pos <= end)
                {
                    if(arr[new_pos]==-1)
                    {
                        if(!visited[new_pos])
                        {
                            visited[new_pos] = true;
                            q.push({new_pos, moves+1});
                        }
                    }
                    else
                    {
                        int target = arr[new_pos];
                        if(!visited[target-1])
                        {
                            visited[target-1] = true;
                            q.push({target-1, moves+1});
                        }
                    }
                }
            }
        }
        return -1;
    }

    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size();
        bool flag = true;
        vector<int>arr;
        for(int i=n-1;i>=0;i--)
        {
            if(flag)
            {
                for(int j=0;j<n;j++)
                {
                    arr.push_back(board[i][j]);
                }
                flag = false;
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    arr.push_back(board[i][j]);
                }
                flag = true;
            }      
        }

        int start = 0;
        int end = arr.size()-1;

        return solve(start, end, arr);
    }
};