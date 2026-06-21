class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        function<void(int, int)> dfs = [&](int open, int close) {
            if ((int)cur.size() == 2 * n) {
                res.push_back(cur);
                return;
            }
            if (open < n) {
                cur += '(';
                dfs(open + 1, close);
                cur.pop_back();
            }
            if (close < open) {
                cur += ')';
                dfs(open, close + 1);
                cur.pop_back();
            }
        };
        dfs(0, 0);
        return res;
    }
};