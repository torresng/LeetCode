#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> hash;
        typedef pair<int, string> PIS;
        priority_queue<PIS> heap;

        for (auto word : words) {
            hash[word]++;
        }

        for (auto item : hash) {
            PIS t(-item.second, item.first);
            heap.push(t);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = heap.top().second;
            heap.pop();
        }
        return res;
    }
};

void test_case_1() {
    vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> ans{"i", "love"};

    vector<string> res = Solution().topKFrequent(words, k);

    assert(res == ans);
}

void test_case_2() {
    vector<string> words{"the", "day", "is",    "sunny", "the",
                         "the", "the", "sunny", "is",    "is"};
    int k = 4;
    vector<string> ans{"the", "is", "sunny", "day"};

    vector<string> res = Solution().topKFrequent(words, k);

    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
