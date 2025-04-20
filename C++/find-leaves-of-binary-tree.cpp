// Time:  O(n)
// Space: O(h)

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        findLeavesHelper(root, &result);
        return result;
    }

private:
    int findLeavesHelper(TreeNode *node, vector<vector<int>> *result) {
        if (node == nullptr) {
            return -1;
        }
        const int level = 1 + max(findLeavesHelper(node->left, result),
                                  findLeavesHelper(node->right, result));
        if (result->size() < level + 1){
            result->emplace_back();
        }
        (*result)[level].emplace_back(node->val);
        return level;
    }
};
