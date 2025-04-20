// Time:  O(n)
// Space: O(w)

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<TreeNode *> q = {root};
        bool is_odd = false;
        while (!empty(q)) {
            vector<TreeNode *> new_q;
            TreeNode *prev = nullptr;
            for (const auto& node : q) {
                if (is_odd) {
                    if (node->val % 2 || (prev && prev->val <= node->val)) {
                        return false;
                    }
                } else {
                    if (node->val % 2 == 0 || (prev && prev->val >= node->val)) {
                        return false;
                    }
                }
                if (node->left) {
                    new_q.emplace_back(node->left);
                }
                if (node->right) {
                    new_q.emplace_back(node->right);
                }
                prev = node;
            }
            q = move(new_q);
            is_odd = !is_odd;
        }
        return true;
    }
};
