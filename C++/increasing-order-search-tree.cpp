// Time:  O(n)
// Space: O(h)

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        return increasingBSTHelper(root, nullptr);
    }

private:
    TreeNode* increasingBSTHelper(TreeNode* root, TreeNode* tail) {
        if (!root) {
            return tail;
        }
        auto result = increasingBSTHelper(root->left, root);
        root->left = nullptr;
        root->right = increasingBSTHelper(root->right, tail);
        return result;
    }
};
