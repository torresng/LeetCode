class RandomizedCollection
{
    unordered_map<int, set<int>> map;
    vector<int> data;

public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        auto exist = map.find(val);
        map[val].insert(data.size());
        data.push_back(val);
        return exist == map.end();
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (map.find(val) == map.end())
        {
            return false;
        }
        int i = *(map[val].begin());
        map[val].erase(i);

        int lastVal = data.back();
        int lastIdx = data.size() - 1;
        if (i != lastIdx)
        {
            int lastVal = data.back();
            data[i] = lastVal;
            map[lastVal].erase(lastIdx);
            map[lastVal].insert(i);
        }
        data.pop_back();
        if (map[val].empty())
        {
            map.erase(val);
        }
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        if (data.empty())
        {
            return -1;
        }
        int i = rand() % data.size();
        return data[i];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */