class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> dfs = [&](int i) {
            if (i == nums.size()) { res.push_back(cur); return; }
            cur.push_back(nums[i]);
            dfs(i + 1);
            cur.pop_back();
            dfs(i + 1);
        };
        dfs(0);
        return res;
    }
};