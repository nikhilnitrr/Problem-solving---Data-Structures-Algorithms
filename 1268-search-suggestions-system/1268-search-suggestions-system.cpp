struct TrieNode
{
    vector<string>suggestions; // top 3 suggestions
    TrieNode* child[26];

    TrieNode(){
        for(int i=0;i<26;i++)
        {
            child[i] = NULL;
        }
    }
};

void insert(string word, TrieNode* root)
{
    TrieNode* curr = root;
    for(int i=0;i<word.length();i++)
    {
        int index = word[i]-'a';
        if(curr->child[index]==NULL)
        {
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
        if(curr->suggestions.size() < 3)
        {
            curr->suggestions.push_back(word);
        }
    }
}


class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        TrieNode* root = new TrieNode();
        sort(products.begin(), products.end());
        for(string product : products)
        {
            insert(product, root);
        }

        vector<vector<string>>result;
        TrieNode* curr = root;
        for(int i=0;i<searchWord.length();i++)
        {
            int index = searchWord[i]-'a';
            curr = curr->child[index];
            if(curr!=NULL)
            {
                result.push_back(curr->suggestions);
            }
            else
            {
                result.push_back({});
            }
        }

        return result;
    }
};