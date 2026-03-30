class LRUCache 
{
public:

    list<pair<int, int>>ls;
    unordered_map<int, list<pair<int, int>>:: iterator>cache;
    int capacity;
    LRUCache(int size) 
    {
        capacity = size;
        ls.clear();
        cache.clear();
    }
    
    int get(int key) 
    {
        if(cache.find(key) == cache.end())
        {
            return -1;
        }
        list<pair<int, int>>:: iterator it = cache[key];
        pair<int, int>p= *it;
        ls.erase(it);
        int value = p.second;
        ls.push_front({key, value});
        cache[key] = ls.begin();
        return value;
    }
    
    void put(int key, int value) 
    {
        // if key is present
        if(cache.find(key)!=cache.end())
        {
            list<pair<int, int>>:: iterator it = cache[key];
            pair<int, int>p = *it;
            ls.erase(it);
            ls.push_front({key, value});
            cache[key] = ls.begin();
            return;
        }

        if(capacity == cache.size())
        {
            pair<int, int>p=ls.back();
            ls.pop_back();
            cache.erase(p.first);
            ls.push_front({key, value});
            cache[key] = ls.begin();
            return;
        }

        ls.push_front({key, value});
        cache[key] = ls.begin();
    }
};
