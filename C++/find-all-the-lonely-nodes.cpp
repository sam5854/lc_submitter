// Time:  O(n)
// Space: O(h)

class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> result;
        vector<TreeNode *> stk = {root};
        while (!stk.empty()) {
            auto node = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            if (node->left && !node->right) {
                result.emplace_back(node->left->val);
            } else if (node->right && !node->left) {
                result.emplace_back(node->right->val);
            }
            stk.emplace_back(node->right);
            stk.emplace_back(node->left);
        }
        return result;
    }
};
