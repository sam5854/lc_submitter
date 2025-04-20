// Time:  O(n)
// Space: O(h)
// dfs solution

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> level_sums;
        dfs(root, 0, &level_sums);
        return distance(level_sums.cbegin(),
                        max_element(level_sums.cbegin(), level_sums.cend())) + 1;
    }

private:
    void dfs(TreeNode *node, int i, vector<int> *level_sums) {
        if (!node) {
            return;
        }
        if (i == level_sums->size()) {
            level_sums->emplace_back();
        }
        (*level_sums)[i] += node->val;
        dfs(node->left, i + 1, level_sums);
        dfs(node->right, i + 1, level_sums);
    }
};
