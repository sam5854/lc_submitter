// Time:  O(n)
// Space: O(h)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        return iter_dfs(root, unordered_set<TreeNode*>(cbegin(nodes), cend(nodes)));
    }

private:
    TreeNode* iter_dfs(TreeNode* node, const unordered_set<TreeNode*>& lookup) {
        TreeNode *result = nullptr;
        vector<tuple<int, TreeNode *, unique_ptr<TreeNode *>, unique_ptr<TreeNode *>, TreeNode **>> stk;
        stk.emplace_back(1, node, nullptr,  nullptr, &result);
        while (!empty(stk)) {
            const auto [step, node, ret1, ret2, ret] = move(stk.back()); stk.pop_back();
            if (step == 1) {
                if (!node || lookup.count(node)) {
                    *ret = node;
                    continue;
                }
                auto ret1 = make_unique<TreeNode *>(), ret2 = make_unique<TreeNode *>();
                auto p1 = ret1.get(), p2 = ret2.get();
                stk.emplace_back(2, node, move(ret1), move(ret2), ret);
                stk.emplace_back(1, node->right, nullptr, nullptr, p2);
                stk.emplace_back(1, node->left, nullptr, nullptr, p1);
            } else if (step == 2) {
                if (*ret1 && *ret2) {
                    *ret = node;
                } else {
                    *ret = *ret1 ? *ret1 : *ret2;
                }
            }
        }
        return result;
    }
};
