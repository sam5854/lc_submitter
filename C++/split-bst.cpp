// Time:  O(n)
// Space: O(h)

class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (!root) {
            return {nullptr, nullptr};
        } else if (root->val <= V) {
            const auto& result = splitBST(root->right, V);
            root->right = result[0];
            return {root, result[1]};
        } else {
            const auto& result = splitBST(root->left, V);
            root->left = result[1];
            return {result[0], root};
        }
    }
};
