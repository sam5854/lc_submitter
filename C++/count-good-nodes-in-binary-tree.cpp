// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        vector<pair<TreeNode *, int>> stk = {{root, root->val}};
        while (!stk.empty()) {
            auto [node, curr_max] = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            curr_max = max(curr_max, node->val);
            result += (curr_max <= node->val);
            stk.emplace_back(node->right, curr_max);
            stk.emplace_back(node->left, curr_max);
        }
        return result;
    }
};
