class Solution 
{
public:

    int get_count(int num)
    {
        int cnt = 0;
        while(num > 1)
        {
            cnt+=(num&1);
            num=num>>1;
        }
        if(num==1)cnt++;
        return cnt;
    }

    vector<int> countBits(int n) 
    {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int res = get_count(i);
            ans.push_back(res);
        }
        return ans;
    }
};
