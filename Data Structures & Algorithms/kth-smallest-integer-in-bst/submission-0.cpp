class Solution {
public:
    int result, count;

    void inorder(TreeNode* node, int k) {
        if (!node) return;
        inorder(node->left, k);
        if (++count == k) { result = node->val; return; }
        inorder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inorder(root, k);
        return result;
    }
};