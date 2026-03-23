#define ll long long 
class Solution 
{
public:
    int firstMissingPositive(vector<int>& arr) 
    {
        int n = arr.size();
        int  i = 0;
        while(i<n)
        {
            ll correct = (ll)arr[i]-1;
            if(arr[i] <=0 || arr[i] > n)
            {
                i++;
            }
            else if(arr[i]!=arr[correct])
            {
                swap(arr[i], arr[correct]);
            }
            else
            {
                i++;
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1)
            {
                ans = i+1;
                break;
            }
        }
        return ans==-1 ? n+1 : ans;
    }
};