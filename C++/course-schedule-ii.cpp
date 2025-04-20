// Time:  O(|V| + |E|)
// Space: O(|E|)
// Kahn’s algorithm (bfs solution)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> in_degree;
        for (const auto& p : prerequisites) {
            ++in_degree[p[0]];
            adj[p[1]].emplace_back(p[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!in_degree.count(i)) {
                q.emplace(i);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            const auto node = q.front(); q.pop();
            result.emplace_back(node);
            for (const auto& i : adj[node]) {
                if (!--in_degree[i]) {
                    q.emplace(i);
                }
            }
        }
        return size(result) == numCourses ? result : vector<int>();
    }
};
