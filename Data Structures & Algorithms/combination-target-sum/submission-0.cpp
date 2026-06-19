class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int, int)> dfs = [&](int i, int rem) {
            if (rem == 0) { res.push_back(cur); return; }
            if (i == nums.size() || rem < 0) return;
            cur.push_back(nums[i]);
            dfs(i, rem - nums[i]);
            cur.pop_back();
            dfs(i + 1, rem);
        };
        dfs(0, target);
        return res;
    }
};