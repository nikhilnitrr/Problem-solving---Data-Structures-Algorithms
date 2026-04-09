struct cmp 
{
    bool operator()(const pair<int, int>&p1, const pair<int, int>&p2)
    {
        if(p1.first == p2.first)
        {
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};


class Solution 
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x), arr[i]});
        }
        vector<int>result;
        while(result.size()!=k)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};