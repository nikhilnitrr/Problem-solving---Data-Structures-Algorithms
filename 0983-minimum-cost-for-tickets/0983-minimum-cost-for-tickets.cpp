class Solution 
{
public:

    void solve(int i, vector<int>&days, int n, vector<int>&costs, int curr_cost, int &min_cost)
    {
        if(i == n)
        {
            min_cost = min(min_cost, curr_cost);
            return;
        }

        solve(i+1, days, n, costs, curr_cost+costs[0], min_cost);

        int j = i;
        int k = i;

        while(j < n && days[j] < days[i]+7)
        {
            j++;
        }

        while(k < n && days[k] < days[i]+30)
        {
            k++;
        }

        solve(j, days, n, costs, curr_cost+costs[1], min_cost);

        solve(k, days, n, costs, curr_cost+costs[2], min_cost);
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n = days.size();
        int min_cost = INT_MAX;
        solve(0, days, n, costs, 0, min_cost);
        return min_cost;
    }
};