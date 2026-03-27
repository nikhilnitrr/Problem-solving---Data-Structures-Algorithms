class Solution 
{
public:

    void shift_left(vector<int>&arr, int k)
    {
        int n = arr.size();
        k=k%n;
        // note : the second argument i.e arr.begin()+k only considers elements from starting till kth (excluding kth)
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
        reverse(arr.begin(), arr.end());
    }
    void shift_right(vector<int>&arr, int k)
    {
        int n = arr.size();
        k=k%n;
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
    }

    bool areSimilar(vector<vector<int>>& arr, int k) 
    {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>temp = arr;

        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                shift_left(temp[i], k);
            }
            else if(i%2 !=0)
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