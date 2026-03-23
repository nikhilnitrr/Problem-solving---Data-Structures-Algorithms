class Solution 
{
public:

    double solve(vector<int>&left, int n, vector<int>&right, int m)
    {
        int low = 0;
        int high = n;
        int total = (n+m+1)/2;
        while(low<=high)
        {
            int first = low+(high-low)/2;
            int second = total - first;

            int a = first==0 ? INT_MIN : left[first-1];
            int b = first==n ? INT_MAX : left[first];

            int c = second==0 ? INT_MIN : right[second-1];
            int d = second==m ? INT_MAX : right[second];

            if(a <=d && c<=b)
            {
                if((m+n)%2 == 0)
                {
                    return (max(a,c) + min(b, d))/2.0;
                }
                else
                {
                    return max(a,c)/1.0;
                }
            }
            if(a > d)
            {
                high = first - 1;
            }
            else
            {
                low = first + 1;
            }
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int l1 = nums1.size();
        int l2 = nums2.size();

        if(l1 < l2)
        {
            return solve(nums1, l1, nums2, l2);
        }
        return solve(nums2, l2, nums1, l1);
    }
};