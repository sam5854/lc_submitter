// Time:  O(n + m)
// Space: O(n + m)
// iterative dfs, tree diameter

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / 2;
        };

        const auto& tree_diameter = [](const auto& edges) {
            vector<vector<int>> adj(size(edges) + 1);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            int result = 0;
            const auto& iter_dfs = [&]() {
                int result = 0;
                using RET = int;
                RET ret{};
                vector<tuple<int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, nullptr, &ret}};
                while (!empty(stk)) {
                    const auto [step, u, p, ret2, ret] = stk.back(); stk.pop_back();
                    if (step == 1) {
                        for (const auto& v : adj[u]) {
                            if (v == p) {
                                continue;
                            }
                            const auto& ret2 = make_shared<RET>();
                            stk.emplace_back(2, -2, -2, ret2, ret);
                            stk.emplace_back(1, v, u, nullptr, ret2.get());
                        }
                    } else if (step == 2) {
                        result = max(result, *ret + (*ret2 + 1));
                        *ret = max(*ret, *ret2 + 1);
                    }
                }
                return result;
            };

            return iter_dfs();
        };

        const int d1 = tree_diameter(edges1);
        const int d2 = tree_diameter(edges2);
        return max({ceil_divide(d1, 2) + 1 + ceil_divide(d2, 2), d1, d2});
    }
};
