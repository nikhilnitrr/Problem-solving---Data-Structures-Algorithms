class Solution 
{
public:


    double find_median(vector<int>&nums1, int n, vector<int>&nums2, int m)
    {
        int total = (m+n+1)/2;
        int low = 0;
        int high = n;
        while(low<=high)
        {
            int first = low+(high-low)/2;
            int second = total - first;

            int a = first==0 ? INT_MIN : nums1[first-1];
            int b = first==n ? INT_MAX : nums1[first];

            int c = second==0 ? INT_MIN : nums2[second-1];
            int d = second==m ? INT_MAX : nums2[second];

            if(a <= d && c <= b)
            {
                if((m+n)%2 == 0)
                {
                    return (max(a, c) + min(b,d))/2.0;
                }
                else
                {
                    return max(a,c)/1.0;
                }
            }
            if(a > d)
            {
                high = first-1;
            }
            else
            {
                low = first + 1;
            }
        }
        return 1.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size();
        int m = nums2.size();

        if(n< m)
        {
            return find_median(nums1, n, nums2, m);
        }
        return find_median(nums2, m, nums1, n);
    }
};