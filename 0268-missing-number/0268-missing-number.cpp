class Solution 
{
public:
    int missingNumber(vector<int>& arr) 
    {
        int n = arr.size();
        int i = 0;
        while(i<n)
        {
            int correct = arr[i];
            if(correct == n)
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
            if(i!=arr[i])
            {
                ans = i;
                break;
            }
        }
        return ans==-1 ? n : ans;
    }
};