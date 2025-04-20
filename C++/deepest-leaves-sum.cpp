// Time:  O(n)
// Space: O(w)

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode *> curr = {root}, prev;
        while (!curr.empty()) {
            prev = move(curr);
            for (const auto& p : prev) {
                for (const auto& child : {p->left, p->right}) {
                    if (child) {
                        curr.emplace_back(child);
                    }
                }
            }
        }
        return accumulate(prev.cbegin(), prev.cend(), 0,
                          [](const auto& x, const auto& y) {
                              return x + y->val;
                          });
    }
};
