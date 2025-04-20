// Time:  O(n^2)
// Space: O(n)
// iterative dfs

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        vector<vector<pair<int, int>>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        const auto& iter_dfs = [&](int u, int p, int dist) {
            int result = 0;
            vector<tuple<int, int, int>> stk = {{u, p, dist}};
            while (!empty(stk)) {
                const auto [u, p, dist] = stk.back(); stk.pop_back();
                if (dist % signalSpeed == 0) {
                    ++result;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    stk.emplace_back(v, u, dist + w);
                }
            }
            return result;
        };
    
        vector<int> result(size(edges) + 1);
        for (int u = 0; u < size(result); ++u) {
            int curr = 0;
            for (const auto& [v, w] : adj[u]) {
                const auto& cnt = iter_dfs(v, u, w);
                result[u] += curr * cnt;
                curr += cnt;
            }
        }
        return result;
    }
};
