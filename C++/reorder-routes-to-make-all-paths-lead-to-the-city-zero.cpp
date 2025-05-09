// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<uint64_t> lookup;
        unordered_map<int, vector<int>> graph;
        for (const auto& connection : connections) {
            lookup.emplace(uint64_t(connection[0]) * n + connection[1]);
            graph[connection[0]].emplace_back(connection[1]);
            graph[connection[1]].emplace_back(connection[0]);
        }
        int result = 0;
        vector<pair<int, int>> stk = {{-1, 0}};
        while (!stk.empty()) {
            const auto [parent, u] = stk.back(); stk.pop_back();
            for (const auto& v : graph[u]) {
                if (v == parent) {
                    continue;
                }
                stk.emplace_back(u, v);
            }
            result += lookup.count(uint64_t(parent) * n + u);
        }
        return result;
    }
};
