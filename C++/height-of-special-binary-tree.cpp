// Time:  O(n)
// Space: O(h)
// dfs

class Solution {
public:
    int heightOfTree(TreeNode* root) {
        int result = -1;
        vector<pair<TreeNode *, int>> stk = {{root, 0}};
        while (!empty(stk)) {
            const auto [u, d] = stk.back(); stk.pop_back();
            result = max(result, d);
            if (u->right && u->right->left != u) {
                stk.emplace_back(u->right, d + 1);
            }
            if (u->left && u->left->right != u) {
                stk.emplace_back(u->left, d + 1);
            }
        }
        return result;
    }
};
