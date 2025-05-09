// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int prev = numeric_limits<int>::min();
        int result = numeric_limits<int>::max();
        dfs(root, &prev, &result);
        return result;
    }

private:
    void dfs(TreeNode* node, int *prev, int *result) {
        if (!node) {
            return;
        }
        dfs(node->left, prev, result);
        if (*prev != numeric_limits<int>::min()) {
            *result = min(*result, node->val - *prev);
        }
        *prev = node->val;
        dfs(node->right, prev, result);
    }
};
