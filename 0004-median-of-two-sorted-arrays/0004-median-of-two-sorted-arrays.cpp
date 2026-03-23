class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>temp;
        for(int num : nums1)
        {
            temp.push_back(num);
        }
        for(int num : nums2)
        {
            temp.push_back(num);
        }
        sort(temp.begin(), temp.end());
        int n = temp.size();
        if(n%2!=0)
        {
            return (double)temp[n/2];
        }
        double a = temp[n/2];
        double b = temp[(n/2)-1];
        return (a+b)/2;
    }
};