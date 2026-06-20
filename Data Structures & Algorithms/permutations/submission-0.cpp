class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        
        function<void()> dfs = [&]() {
            if (cur.size() == nums.size()) {
                res.push_back(cur);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                used[i] = true;
                cur.push_back(nums[i]);
                dfs();
                cur.pop_back();
                used[i] = false;
            }
        };
        
        dfs();
        return res;
    }
};