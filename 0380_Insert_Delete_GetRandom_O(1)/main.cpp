// T = O(1), S = (n)
class RandomizedSet
{
    unordered_map<int, int> map;
    vector<int> data;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (map.find(val) != map.end())
        {
            return false;
        }
        map[val] = data.size();
        data.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (map.find(val) == map.end())
        {
            return false;
        }
        int i = map[val];
        int lastVal = data.back();
        data.pop_back();
        data[i] = lastVal;
        map[lastVal] = i;
        map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int i = rand() % data.size();
        return data[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */