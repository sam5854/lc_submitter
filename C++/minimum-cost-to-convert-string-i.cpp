// Time:  O(o + k * eloge + n), k = len(set(original)), e is the number of edges reachable from a given node u
// Space: O(o + k * v), v is the number of nodes reachable from a given node u
// dijkstra's algorithm, memoization

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        static const int INF = numeric_limits<int>::max();

        unordered_map<int, unordered_map<int, int>> dist;
        for (int i = 0; i < size(original); ++i) {
            const int u = original[i] - 'a';
            const int v = changed[i] - 'a';
            if (!dist[u].count(v)) {
                dist[u][v] = INF;
            }
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        const auto& dijkstra = [&](int start) {
            unordered_map<int, int> best = {{start, 0}};
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(0, start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr > best[u]) {
                    continue;
                }
                for (auto [v, w] : dist[u]) {
                    if (best.count(v) && best[v] - curr <= w) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v], v);
                }
            }
            return best;
        };
        
        unordered_map<int, unordered_map<int, int>> memo;
        const auto& memoization = [&](int u, int v) {            
            if (!memo.count(u)) {
                memo[u] = dijkstra(u);
            }
            return memo[u].count(v) ? memo[u][v] : INF;
        };

        int64_t result = 0;
        for (int i = 0; i < size(source); ++i) {
            const int u = source[i] - 'a';
            const int v = target[i] - 'a';
            const int d = memoization(u, v) ;
            if (d == INF) {
                return -1;
            }
            result += d;
        }
        return result;
    }
};
