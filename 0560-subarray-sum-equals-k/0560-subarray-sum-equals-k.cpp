class Solution 
{
public:
    int subarraySum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int result = 0;
        vector<int>prefix(n, 0);
        prefix[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }

        unordered_map<int, int>um;

        for(int i=0;i<n;i++)
        {
            if(prefix[i]==target)
            {
                result++;
            }
            if(um.find(prefix[i]-target)!=um.end())
            {
                result+=um[prefix[i]-target];
            }
            um[prefix[i]]++;
        }
        return result;
    }
};