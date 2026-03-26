class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int>prefix(n, 0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int, int>um;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(prefix[i] == k)
            {
                cnt++;
            }
            if(um.find(prefix[i]-k)!=um.end())
            {
                cnt+=(um[prefix[i]-k]);
            }
            um[prefix[i]]++;
        }
        return cnt;
    }
};