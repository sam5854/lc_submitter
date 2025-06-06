// Time:  O(n)
// Space: O(n)
// iterative dfs, tree dp

class Solution {
public:
    long long maxScore(vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(size(edges));
        for (int i = 1; i < size(edges); ++i) {
            adj[edges[i][0]].emplace_back(i, edges[i][1]);
        }

        const auto& iter_dfs = [&]() {
            vector<pair<int64_t, int64_t>> result(size(adj));
            vector<pair<int, int>> stk = {{1, 0}};
            while (!empty(stk)) {
                const auto [step, u] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (empty(adj[u])) {
                        continue;
                    }
                    stk.emplace_back(2, u);
                    for (const auto& [v, _] : adj[u]) {
                        stk.emplace_back(1, v);
                    }
                } else if (step == 2) {
                    int64_t without_u = 0;
                    for (const auto& [v, _] : adj[u]) {
                        without_u += max(result[v].first, result[v].second);
                    }
                    int64_t with_u = 0;
                    for (int i = 0; i < size(adj[u]); ++i) {
                        const auto& [v, w] = adj[u][i];
                        with_u = max(with_u, without_u - max(result[v].first, result[v].second) + (result[v].second + w));
                    }
                    result[u] = make_pair(with_u, without_u);
                }
            }
            return max(result[0].first, result[0].second);
        };

        return iter_dfs();
    }
};
