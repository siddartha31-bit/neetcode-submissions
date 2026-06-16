class Solution {
public:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        int good = node->val >= maxSoFar ? 1 : 0;
        maxSoFar = max(maxSoFar, node->val);
        return good + dfs(node->left, maxSoFar) + dfs(node->right, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};