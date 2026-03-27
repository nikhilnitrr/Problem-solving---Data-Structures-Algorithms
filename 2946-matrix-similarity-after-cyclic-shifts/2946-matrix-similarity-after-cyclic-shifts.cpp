class Solution 
{
public:

    void shift_left(vector<int>&arr, int k)
    {
        int n = arr.size();
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
        reverse(arr.begin(), arr.end());
    }
    void shift_right(vector<int>&arr, int k)
    {
        int n = arr.size();
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
    }

    bool areSimilar(vector<vector<int>>& arr, int k) 
    {
        int n = arr.size();
        int m = arr[0].size();
        k = k%n;
        vector<vector<int>>temp = arr;

        for(int i=0;i<n;i++)
        {
            if(i%2 == 0 && k!=n)
            {
                shift_left(temp[i], k);
            }
            else if(i%2 !=0 && k!=n)
            {
                shift_right(temp[i], k);
            }
        }
        if(temp == arr)
        {
            return true;
        }
        return false;
    }
};