class Solution 
{
public:
    int reverse(int num) 
    {
        int min_value = INT_MIN;
        int max_value = INT_MAX;
        int res = 0;

        while(num)
        {
            int digit = (num%10);
            num = num / 10;

            if(res > max_value/10 || (res == max_value/10 && digit >= max_value%10))
            {
                return 0;
            }
            if(res < min_value/10 || (res == min_value/10 && digit <= min_value%10))
            {
                return 0;
            }

            res = (res * 10) + digit;
        }
        return res;
    }
};
