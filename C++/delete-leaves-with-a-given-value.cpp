// Time:  O(n)
// Space: O(h)

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        return (root->left == root->right && root->val == target) ? nullptr : root;
    }
};
