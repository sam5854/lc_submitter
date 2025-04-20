// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)
// bi-bfs solution

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        return bi_bfs(adj, start, end) >= 0;
    }

private:
    int bi_bfs(const unordered_map<int, vector<int>>& adj,
               const int start,
               const int target) {
        unordered_set<int> left = {start}, right = {target};
        unordered_set<int> lookup;
        int steps = 0;
        while (!empty(left)) {
            for (const auto& pos : left) {
                lookup.emplace(pos);
            }
            unordered_set<int> new_left;
            for (const auto& pos : left) {
                if (right.count(pos)) {
                    return steps;
                }
                if (!adj.count(pos)) {
                    continue;
                }
                for (const auto& nei : adj.at(pos)) {
                    if (lookup.count(nei)) {
                        continue;
                    }
                    new_left.emplace(nei);
                }
            }
            left = move(new_left);
            ++steps;
            if (size(left) > size(right)) {
                swap(left, right);
            }
        }
        return -1;
    }
};
