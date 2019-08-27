#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
  public:
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int> down;

    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        if (down.empty() || num >= down.top()) {
            up.push(num);
        } else {
            down.push(num);
            up.push(down.top());
            down.pop();
        }

        if (up.size() > down.size() + 1) {
            down.push(up.top());
            up.pop();
        }
    }

    double findMedian() {
        if (down.size() + up.size() & 1) {
            return up.top();
        } else {
            return (down.top() + up.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

void test_case_1() {
    MedianFinder m = MedianFinder();
    m.addNum(1);
    m.addNum(2);
    assert(m.findMedian() == 1.5);
    m.addNum(3);
    assert(m.findMedian() == 2);
}

int main() {
    test_case_1();

    return 0;
}
