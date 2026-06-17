class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int l = max(0, dfs(node->left));
            int r = max(0, dfs(node->right));
            ans = max(ans, l + r + node->val);
            return max(l, r) + node->val;
        };
        dfs(root);
        return ans;
    }
};
