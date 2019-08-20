#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> stk, stk_min;

  public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        stk.push(x);
        if (stk_min.empty()) {
            stk_min.push(x);
        } else {
            stk_min.push(min(x, stk_min.top()));
        }
    }

    void pop() {
        stk.pop();
        stk_min.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return stk_min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

void test_case_1() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3);
    minStack.pop();
    assert(minStack.top() == 0);
    assert(minStack.getMin() - 2);
}

int main() {
    test_case_1();

    return 0;
}
