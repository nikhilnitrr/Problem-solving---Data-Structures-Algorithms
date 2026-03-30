class Solution 
{
public:

    bool solve(int index, string s1, string s2)
    {
        if(s1 == s2)
        {
            return true;
        }
        swap(s1[index%4], s1[(index+2)%4]);
        if(s1 == s2)
        {
            return true;
        }
        swap(s1[(index+1)%4], s1[(index+3)%4]);
        if(s1 == s2)
        {
            return true;
        }
        return false;
    }

    bool canBeEqual(string s1, string s2) 
    {
        if(s1 == s2)
        {
            return true;
        } 
        return solve(0, s1, s2) || solve(1, s1, s2);
    }
};