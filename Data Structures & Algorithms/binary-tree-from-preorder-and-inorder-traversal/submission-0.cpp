class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> idx;
        for (int i = 0; i < inorder.size(); i++)
            idx[inorder[i]] = i;
        int pre = 0;
        function<TreeNode*(int, int)> solve = [&](int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            int mid = idx[preorder[pre++]];
            TreeNode* node = new TreeNode(inorder[mid]);
            node->left = solve(l, mid - 1);
            node->right = solve(mid + 1, r);
            return node;
        };
        return solve(0, inorder.size() - 1);
    }
};