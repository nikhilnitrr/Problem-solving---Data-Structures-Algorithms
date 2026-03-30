class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int res = 0;
        for(int i=0;i<32;i++)
        {
            // check if ith bit is set or not
            if(n&(1<<i))
            {
                // set (31 - i)th bit of res
                res = res | (1<<(31-i));
            }
        }  
        return res;
    }
};
