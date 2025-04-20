// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int result = 0;
        dfs(root, &result);
        return result;
    }

private:
    int dfs(TreeNode* root, int *result) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        *result += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};
