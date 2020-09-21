#include <iostream>
#include <map>
#include <vector>

using namespace std;

class SummaryRanges {
  public:
    map<int, int> L, R;
    /** Initialize your data structure here. */
    SummaryRanges() {}

    void addNum(int val) {
        if (L.size()) {
            auto it = L.lower_bound(val);
            if (it != L.end() && it->second <= val) {
                return;
            }
        }

        int left = L.count(val - 1), right = R.count(val + 1);
        if (left && right) {
            R[L[val - 1]] = R[val + 1];
            L[R[val + 1]] = L[val - 1];
            L.erase(val - 1), R.erase(val + 1);
        } else if (left) {
            R[L[val - 1]] = val;
            L[val] = L[val - 1];
            L.erase(val - 1);
        } else if (right) {
            L[R[val + 1]] = val;
            R[val] = R[val + 1];
            R.erase(val + 1);
        } else {
            R[val] = L[val] = val;
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto item : R) {
            res.push_back({item.first, item.second});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

void test_case_1() {
    SummaryRanges *obj = new SummaryRanges();
    vector<vector<int>> ans;
    vector<vector<int>> res;

    obj->addNum(1);
    ans = {{1, 1}};
    res = obj->getIntervals();
    sort(res.begin(), res.end());
    assert(res == ans);

    obj->addNum(3);
    ans = {{1, 1}, {3, 3}};
    res = obj->getIntervals();
    sort(res.begin(), res.end());
    assert(res == ans);

    obj->addNum(7);
    ans = {{1, 1}, {3, 3}, {7, 7}};
    res = obj->getIntervals();
    sort(res.begin(), res.end());
    assert(res == ans);

    obj->addNum(2);
    ans = {{1, 3}, {7, 7}};
    res = obj->getIntervals();
    sort(res.begin(), res.end());
    assert(res == ans);

    obj->addNum(6);
    ans = {{1, 3}, {6, 7}};
    res = obj->getIntervals();
    sort(res.begin(), res.end());
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
