class Solution 
{
public:

    bool get_distance(string src, string dst, unordered_map<string, vector<pair<string, double>>>&adj, unordered_set<string>&visited, double &cost)
    {
        if(adj.find(src)==adj.end() || adj.find(dst)==adj.end())
        {
            return false;
        }
        if(src == dst)
        {
            return true;
        }
        visited.insert(src);
        for(auto x : adj[src])
        {
            string u = x.first;
            double c = x.second;
            if(visited.find(u)==visited.end() && get_distance(u, dst, adj, visited, cost))
            {
                cost = cost*c;
                return true;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, vector<pair<string, double>>>adj;
        vector<double>result;
        for(int i=0;i<equations.size();i++)
        {
            string from = equations[i][0];
            string to = equations[i][1];

            adj[from].push_back({to, values[i]});
            adj[to].push_back({from, 1.0/values[i]});
        }

        for(int i=0;i<queries.size();i++)
        {
            string src = queries[i][0];
            string dst = queries[i][1];
            unordered_set<string>visited;
            double cost = 1;
            if(get_distance(src, dst, adj, visited, cost))
            {
                result.push_back(cost);
            }
            else
            {
                result.push_back(-1.0);
            }
        }
        return result;
    }
};