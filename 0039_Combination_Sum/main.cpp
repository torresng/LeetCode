// T = O(n^(target/min)), S = O(target/min)
class Solution {
    vector<vector<int>> res;
    vector<int> v;
    
    void dfs(vector<int> &candidates, int start, int target) {
        if(target == 0) {
            res.push_back(v);
            return;
        }
        if(target < 0) {
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] > target) {
                return;
            }
            v.push_back(candidates[i]);
            dfs(candidates, i, target-candidates[i]);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) { return {}; }
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};
