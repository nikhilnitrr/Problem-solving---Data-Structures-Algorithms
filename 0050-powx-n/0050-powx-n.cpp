#define ll long long
class Solution 
{
public:
    double solve(double x, ll n, unordered_map<int, double>&um)
    {
        if(um.find(n)!=um.end())
        {
            return um[n];
        }
        if(n==1)
        {
            return x;
        }
        if(n%2==0)
        {
            return um[n] = (solve(x, n/2, um) * solve(x, n/2, um));
        }
        return um[n] = (x*solve(x, n/2, um) * solve(x, n/2, um));
    }

    double myPow(double x, int n) 
    {
        if(n==0)
        {
            return 1;
        }
        ll power = n > 0 ? (ll)n : ((ll)n*-1);
        unordered_map<int, double>dp;
        double ans = solve(x, power, dp);
        if(n > 0)
        {
            return ans;
        }
        return 1/ans;
    }
};