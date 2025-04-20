// Time:  O(nlogn + e)
// Space: O(n + e)
// dijkstra's algorithm

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        static const int INF = numeric_limits<int>::max();

        vector<unordered_map<int, int>> adj(n);
        const auto& dijkstra = [&]() {
            vector<int> best(size(adj), INF);
            best[0] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(0, 0);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr != best[u]) {
                    continue;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (!(max(w, curr) < best[v])) {
                        continue;
                    }
                    best[v] = max(w, curr);
                    min_heap.emplace(best[v], v);
                }
            }
            const int result = ranges::max(best);
            return result != INF ? result : -1;
        };

        for (const auto& e : edges) {
            adj[e[1]][e[0]] = adj[e[1]].count(e[0]) ? min(adj[e[1]][e[0]], e[2]) : e[2];
        }
        return dijkstra();
    }
};
