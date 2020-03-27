class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int n = numbers[i] + numbers[j];
            if (n > target) {
                j--;
            } else if (n < target) {
                i++;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
};
