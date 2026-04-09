struct cmp {
    bool operator()(vector<int>const &a, vector<int>const &b)
    {
        return a[1] > b[1];
    }
};


class Solution 
{
public:
    int maximumUnits(vector<vector<int>>& nums, int capacity) 
    {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end(), cmp());
        for(int i=0;i<n;i++)
        {
            int box_count = min(capacity, nums[i][0]);
            result+=(box_count * nums[i][1]);
            capacity-=box_count;
        }
        return result;
    }
};