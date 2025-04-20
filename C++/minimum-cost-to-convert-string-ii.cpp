// Time:  O(o * l + k * eloge + n * c * l), e is the number of edges reachable from a given node u, o = len(original), l = max(len(x) for x in original), k = len(lookups), c = len({len(x) for x in original})
// Space: O(o * l + k * v + c + l), v is the number of nodes reachable from a given node u
// hash table, dijkstra's algorithm, dp, memoization

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        static const auto INF = numeric_limits<int64_t>::max();

        unordered_map<int, unordered_map<string, int>> lookups;
        for (const auto& x : original) {
            const int l = size(x);
            auto& lookup = lookups[l];
            if (!lookup.count(x)) {
                lookup[x] = size(lookup);
            }
        }
        for (const auto& x : changed) {
            const int l = size(x);
            auto& lookup = lookups[l];
            if (!lookup.count(x)) {
                lookup[x] = size(lookup);
            }
        }
        unordered_map<int, vector<vector<int64_t>>> dists;
        for (const auto& [l, lookup] : lookups) {
            auto& dist = dists[l];
            dist.assign(size(lookup), vector<int64_t>(size(lookup), INF));
            for (int u = 0; u < size(dist); ++u) {
                dist[u][u] = 0;
            }
        }
        for (int i = 0; i < size(original); ++i) {
            const int l = size(original[i]);
            auto& lookup = lookups[l];
            auto& dist = dists[l];
            const int u = lookup[original[i]];
            const int v = lookup[changed[i]];
            dist[u][v] = min(dist[u][v], static_cast<int64_t>(cost[i]));
        }
        const auto& dijkstra = [&](const auto& dist, int start) {
            vector<int64_t> best(size(dist), INF);
            best[start] = 0;
            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
            min_heap.emplace(0, start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr > best[u]) {
                    continue;
                }
                for (int v = 0; v < size(dist[u]); ++v) {
                    const auto& w = dist[u][v];
                    if (best[v] - curr <= w) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v], v);
                }
            }
            return best;
        };
        
        unordered_map<int, unordered_map<int, vector<int64_t>>> memo;
        const auto& memoization = [&](int l, const auto& dist, int u, int v) {   
            if (!memo[l].count(u)) {
                memo[l][u] = dijkstra(dist, u);
            }
            return memo[l][u][v];
        };

        unordered_set<int> candidates;
        int l = 0;
        for (const auto& x : original) {
            candidates.emplace(size(x));
            l = max(l, static_cast<int>(size(x)));
        }
        vector<int64_t> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % size(dp)] = min(dp[(i + 1) % size(dp)], dp[i % size(dp)]);
            }
            for (const auto& l : candidates) {
                if (i + l > size(source)) {
                    continue;
                }
                auto& lookup = lookups[l];
                auto& dist = dists[l];
                const auto& u = source.substr(i, l);
                const auto& v = target.substr(i, l);
                if (lookup.count(u) && lookup.count(v) && memoization(l, dist, lookup[u], lookup[v]) != INF) {
                    dp[(i + l) % size(dp)] = min(dp[(i + l) % size(dp)], dp[i % size(dp)] + memoization(l, dist, lookup[u], lookup[v]));
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(source) % size(dp)] != INF ? dp[size(source) % size(dp)] : -1;
    }
};
