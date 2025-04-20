// Time:  O(n)
// Space: O(n)
// bfs

class Solution {
public:
    vector<int> lastMarkedNodes(vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&](int root) {
            int new_root = -1;
            vector<int> dist(size(adj), -1);
            dist[root] = 0;
            vector<int> q = {root};
            while (!empty(q)) {
                new_root = q[0];
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (dist[v] != -1) {
                            continue;
                        }
                        dist[v] = dist[u] + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return pair(dist, new_root);
        };

        const auto& [x, u] = bfs(0);
        const auto& [dist1, v] = bfs(u);
        const auto& [dist2, y] = bfs(v);
        vector<int> result(size(adj));
        for (int w = 0; w < size(adj); ++w) {
            result[w] = dist1[w] > dist2[w] ? u : v;
        }
        return result;
    }
};
