// Time:  O(n)
// Space: O(h)

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lcaDeepestLeavesHelper(root).second;
    }

private:
    pair<int, TreeNode*> lcaDeepestLeavesHelper(TreeNode *root) {
        if (!root) {
            return {0, nullptr};
        }
        const auto& [d1, lca1] = lcaDeepestLeavesHelper(root->left);
        const auto& [d2, lca2] = lcaDeepestLeavesHelper(root->right);
        if (d1 > d2) {
            return {d1 + 1, lca1};
        }
        if (d1 < d2) {
            return {d2 + 1, lca2};
        }
        return {d1 + 1, root};
    }
};
