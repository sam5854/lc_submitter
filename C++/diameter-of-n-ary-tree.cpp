// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int diameter(Node* root) {
        return iter_dfs(root).first;
    }

private:
    pair<int, int> iter_dfs(Node *root) {
        using RET = pair<int, int>;
        RET result;
        vector<tuple<int, Node *, shared_ptr<RET>, RET *>> stk = {{1, root, nullptr, &result}};
        while (!stk.empty()) {
            const auto [step, node, ret2, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                for (int i = node->children.size() - 1; i >= 0; --i) {
                    const auto& ret2 = make_shared<RET>();
                    stk.emplace_back(2, nullptr, ret2, ret);
                    stk.emplace_back(1, node->children[i], nullptr, ret2.get());
                }
            } else {
                ret->first = max(ret->first, max(ret2->first, ret->second + ret2->second + 1));
                ret->second = max(ret->second, ret2->second + 1);
            }
        }
        return result;
    }
};
