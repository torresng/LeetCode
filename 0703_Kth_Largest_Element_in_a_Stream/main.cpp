class KthLargest {
  public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int k;
    // T = O(nlogk)
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (auto num : nums) {
            add(num);
        }
    }

    // T = O(logk)
    int add(int val) {
        if (heap.size() < k) {
            heap.push(val);
        } else {
            if (heap.top() < val) {
                heap.pop();
                heap.push(val);
            }
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
