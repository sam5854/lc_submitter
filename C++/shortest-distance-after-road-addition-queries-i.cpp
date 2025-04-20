// Time:  O(n^2)
// Space: O(n^2)
// bfs

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int u = 0; u + 1 < n; ++u) {
            adj[u].emplace_back(u + 1);
        }
        vector<int> dist(n);
        iota(begin(dist), end(dist), 0);
        const auto& bfs = [&](int u, int v) {
            adj[u].emplace_back(v);
            vector<int> q = {u};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (dist[u] + 1 >= dist[v]) {
                            continue;
                        }
                        dist[v] = dist[u] + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return dist[n - 1];
        };

        vector<int> result;
        result.reserve(n);
        for (const auto& q : queries) {
            result.emplace_back(bfs(q[0], q[1]));
        }
        return result;
    }
};
