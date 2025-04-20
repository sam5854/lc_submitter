// Time:  O(n)
// Space: O(h)
// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        return iter_dfs(distance, root);
    }

private:
    int iter_dfs(int distance, TreeNode *root) {
        using RET = unordered_map<int, int>;
        int result = 0;
        RET ret;
        vector<tuple<int, TreeNode *, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk = {{1, root, nullptr, nullptr, &ret}};
        while (!stk.empty()) {
            const auto [step, node, left, right, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (!node) {
                    continue;
                }
                if (!node->left && !node->right) {
                    (*ret)[0] = 1;
                    continue;
                }
                const auto& left = make_shared<RET>(), &right = make_shared<RET>();
                stk.emplace_back(2, nullptr, left, right, ret);
                stk.emplace_back(1, node->right, nullptr, nullptr, right.get());
                stk.emplace_back(1, node->left, nullptr, nullptr, left.get());
            } else {
                for (const auto& [left_d, left_c] : *left) {
                    for (const auto& [right_d, right_c] : *right) {
                        if (left_d + right_d + 2 <= distance) {
                            result += left_c * right_c;
                        }
                    }
                }
                for (const auto& [left_d, left_c] : *left) {
                    (*ret)[left_d + 1] += left_c;
                }
                for (const auto& [right_d, right_c] : *right) {
                    (*ret)[right_d + 1] += right_c;
                }
            }
        }
        return result;
    }
};
