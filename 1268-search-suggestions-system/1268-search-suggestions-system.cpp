class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        int n = products.size();
        vector<vector<string>>result;
        sort(products.begin(), products.end());

        for(int len=1;len<=searchWord.length();len++)
        {
            string prefix = searchWord.substr(0, len);
            vector<string>temp;
            for(int i=0;i<products.size();i++)
            {
                if(products[i].substr(0, len)==prefix)
                {
                    temp.push_back(products[i]);
                    if(temp.size()==3)
                    {
                        break;
                    }
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};