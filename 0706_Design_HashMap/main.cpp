#include <list>
#include <vector>

using namespace std;

class MyHashMap {
    const int N = 20011;
    vector<list<pair<int, int>>> hash;

  public:
    /** Initialize your data structure here. */
    MyHashMap() { hash = vector<list<pair<int, int>>>(N); }

    list<pair<int, int>>::iterator find(int key) {
        int t = key % N;
        for (auto it = hash[t].begin(); it != hash[t].end(); it++) {
            if (it->first == key) {
                return it;
            }
        }
        return hash[t].end();
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto it = find(key);
        int t = key % N;
        if (it != hash[t].end()) {
            it->second = value;
        } else {
            hash[t].push_back({key, value});
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key) {
        auto it = find(key);
        int t = key % N;
        if (it != hash[t].end()) {
            return it->second;
        } else {
            return -1;
        }
    }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key) {
        auto it = find(key);
        int t = key % N;
        if (it != hash[t].end()) {
            hash[t].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

void test_case_1() {
    MyHashMap hashMap = MyHashMap();
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    assert(hashMap.get(1) == 1);  // returns 1
    assert(hashMap.get(3) == -1); // returns -1 (not found)
    hashMap.put(2, 1);            // update the existing value
    assert(hashMap.get(2) == 1);  // returns 1
    hashMap.remove(2);            // remove the mapping for 2
    assert(hashMap.get(2) == -1); // returns -1 (not found)
}

int main() {
    test_case_1();

    return 0;
}
