class Solution {
public:
    bool dfs(TreeNode* node, long min, long max) {
        if (!node) return true;
        if (node->val <= min || node->val >= max) return false;
        return dfs(node->left, min, node->val) && dfs(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};