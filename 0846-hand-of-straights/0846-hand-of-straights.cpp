class Solution 
{
public:
    bool isNStraightHand(vector<int>& nums, int m) 
    {
        int n = nums.size();
        if(n%m !=0)
        {
            return false;
        }
        int groups = 0;
        map<int, int>um;
        for(int i=0;i<n;i++)
        {
            um[nums[i]]++;
        }

        while(!um.empty())
        {
            int cnt = 0;
            for(auto x: um)
            {
                int temp = x.first;
                cnt++;

                um[temp]--;

                if(um[temp]==0)
                {
                    um.erase(temp);
                }

                temp++;
                while(cnt!=m && !um.empty() && um.find(temp)!=um.end())
                {
                    um[temp]--;
                    if(um[temp] == 0)
                    {
                        um.erase(temp);
                    }
                    cnt++;
                    temp++;
                }
                if(cnt==m)
                {
                    groups++;
                    break;
                }
                if(cnt!=m)
                {
                    return false;
                }
            }
        }
        return groups == n/m;
    }
};
