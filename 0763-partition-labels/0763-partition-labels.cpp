class Solution 
{
public:
    vector<int> partitionLabels(string str) 
    {
        int n = str.length();

        vector<int>arr[26];
        vector<int>result;

        for(int i=0;i<str.length();i++)
        {
            int index = str[i]-'a';
            arr[index].push_back(i);
        }

        vector<bool>visited(26, false);
        vector<vector<int>>temp;

        for(int i=0;i<n;i++)
        {
            int index = str[i]-'a';
            if(!visited[index])
            {
                visited[index] = true;
                temp.push_back({arr[index].front(), arr[index].back()});
            }
        }

        int i=0;
        int j=1;
        while(j<temp.size())
        {
            int curr_end = temp[i].back();
            int next_start = temp[j].front();


            // overlapping
            if(next_start <= curr_end)
            {
                temp[j] = {min(temp[i].front(), temp[j].front()), max(temp[i].back(), temp[j].back())};
                i=j;
                j++;
            }
            else
            {
                result.push_back(temp[i].back() - temp[i].front()+1);
                i=j;
                j++;
            }
        }
        vector<int>aux=temp.back();
        result.push_back(aux.back() - aux.front()+1);
        return result;
    }
};
