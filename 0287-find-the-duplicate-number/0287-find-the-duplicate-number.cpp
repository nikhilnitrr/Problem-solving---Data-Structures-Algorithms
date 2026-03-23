class Solution 
{
public:
    int findDuplicate(vector<int>& arr) 
    {
        int n = arr.size();
        int i=0;
        while(i<n)
        {
            int correct = arr[i]-1;
            if(arr[i]!=arr[correct])
            {
                swap(arr[i], arr[correct]);
            }
            else
            {
                i++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i+1 != arr[i])
            {
                return arr[i];
            }
        }
        return 0;
    }
};