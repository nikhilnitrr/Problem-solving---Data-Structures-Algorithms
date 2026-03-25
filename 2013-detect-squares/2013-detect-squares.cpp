class DetectSquares 
{
public:

    bool is_diagonal(vector<int>&first, vector<int>&second)
    {
        if(abs(first[0] - second[0]) == abs(first[1] - second[1]) && first!=second) // Imp. don't consider same point for diagonal
        {
            return true;
        }
        return false;
    }

    map<vector<int>, int>um;

    DetectSquares() 
    {
        um.clear();
    }
    
    void add(vector<int> point) 
    {
        um[point]++;
    }
    
    int count(vector<int> point) 
    {
        int result = 0;
        for(auto p : um)
        {
            vector<int>temp = p.first;
            int cnt = p.second;

            if(is_diagonal(point, temp))
            {
                if(um.find({point[0], temp[1]})!=um.end() && um.find({temp[0], point[1]})!=um.end())
                {
                    result+=(cnt*um[{point[0], temp[1]}]*um[{temp[0], point[1]}]);
                }
            }
        }
        return result;
    }
};
