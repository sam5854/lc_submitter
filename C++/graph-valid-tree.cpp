// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)
// Same complexity, but faster version.

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        unordered_map<int, vector<int>> neighbors;
        for (const auto& edge : edges) {
            neighbors[edge.first].emplace_back(edge.second);
            neighbors[edge.second].emplace_back(edge.first);
        }

        queue<int> q;
        q.emplace(0);
        unordered_set<int> visited;
        visited.emplace(0);
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            for (const auto& node : neighbors[i]) {
                if (!visited.count(node)) {
                    visited.emplace(node);
                    q.emplace(node);
                }
            }
        }
        return visited.size() == n;
    }
};
