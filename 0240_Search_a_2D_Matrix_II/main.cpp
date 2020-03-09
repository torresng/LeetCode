class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            int t = matrix[i][j];
            if (t == target) {
                return true;
            }
            if (t > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};
