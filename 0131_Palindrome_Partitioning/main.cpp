// T = O(2^n), S = O(n^2)
class Solution {
    vector<vector<string>> res;
    vector<string> elem;

    void partition(string s, int start, vector<vector<bool>> d) {
        if (start >= s.size()) {
            res.push_back(elem);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (d[start][end]) {
                cout << start << ":" << end << endl;
                elem.push_back(s.substr(start, end - start + 1));
                partition(s, end + 1, d);
                elem.pop_back();
            }
        }
    }

  public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return res;
        }
        int n = s.size();
        vector<vector<bool>> d(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    d[i][j] = true;
                } else if (i + 1 == j) {
                    d[i][j] = s[i] == s[j];
                } else {
                    d[i][j] = s[i] == s[j] && d[i + 1][j - 1];
                }
            }
        }
        partition(s, 0, d);
        return res;
    }
};
