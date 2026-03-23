class Solution 
{
public:
    int missingNumber(vector<int>& arr) 
    {
        int n = arr.size();
        int i = 0;
        while(i<n)
        {
            if(i==arr[i])
            {
                i++;
            }
            else if(arr[i]==n)
            {
                i++;
            }
            else
            {
                while(arr[i]!=i)
                {
                    swap(arr[i], arr[arr[i]]);
                    if(arr[i]==n)
                    {
                        break;
                    }
                }
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(i!=arr[i])
            {
                ans = i;
                break;
            }
        }
        return ans==-1 ? n : ans;
    }
};