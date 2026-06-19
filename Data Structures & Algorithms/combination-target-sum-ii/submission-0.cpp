class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int, int)> dfs = [&](int i, int rem) {
            if (rem == 0) { res.push_back(cur); return; }
            for (int j = i; j < candidates.size(); j++) {
                if (candidates[j] > rem) break;
                if (j > i && candidates[j] == candidates[j-1]) continue;
                cur.push_back(candidates[j]);
                dfs(j + 1, rem - candidates[j]);
                cur.pop_back();
            }
        };
        dfs(0, target);
        return res;
    }
};