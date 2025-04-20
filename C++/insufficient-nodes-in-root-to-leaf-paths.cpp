// Time:  O(n)
// Space: O(h)

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) {
            return nullptr;
        }
        if (!root->left && !root->right) {
            return root->val < limit ? nullptr : root;
        }
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);
        if (!root->left && !root->right) {
            return nullptr;
        }
        return root;
    }
};
