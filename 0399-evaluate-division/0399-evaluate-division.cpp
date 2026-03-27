class Solution 
{
public:

    void get_distance(string src, string dst, unordered_map<string, vector<pair<string, double>>>&adj, unordered_set<string>&visited, double &cost, double temp)
    {
        if(adj.find(src)==adj.end() || adj.find(dst)==adj.end())
        {
            cost = -1.0;
            return;
        }
        if(src == dst)
        {
            cost = temp;
            return;
        }
        for(auto x : adj[src])
        {
            string u = x.first;
            if(visited.find(u)==visited.end())
            {
                double c = x.second;
                visited.insert(u);
                get_distance(u, dst, adj, visited, cost, temp*c);
                visited.erase(u);
            }
        }
        
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
            double cost = -1.0;
            get_distance(src, dst, adj, visited, cost, 1.0);
            result.push_back(cost);
        }
        return result;
    }
};