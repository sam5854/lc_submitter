// Time:  O(|V| + |E|) = O(|E|) since graph is connected, O(|E|) >= O(|V|)
// Space: O(|V| + |E|) = O(|E|)

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0] - 1].emplace_back(edge[1] - 1);
            adj[edge[1] - 1].emplace_back(edge[0] - 1);
        }
        return calc_time(time, change, bi_bfs(adj, 0, n - 1));
    }

private:
    // Template:
    // https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/nearest-exit-from-entrance-in-maze.cpp
    int bi_bfs(const vector<vector<int>>& adj, int start, int end) {
        unordered_set<int> left = {start}, right = {end}, lookup;
        int result = 0, steps = 0;
        while (!empty(left) && (!result || result + 2 > steps)) {  // modified
            for (const auto& u : left) {
                lookup.emplace(u);
            }
            unordered_set<int> new_left;
            for (const auto& u : left) {
                if (right.count(u)) {
                    if (!result) {  // modified
                        result = steps;
                    } else if (result < steps) {  // modified
                        return result + 1;
                    }
                }
                for (const auto& v : adj[u]) {
                    if (lookup.count(v)) {
                        continue;
                    }
                    new_left.emplace(v);
                }
            }
            left = move(new_left);
            ++steps;
            if (size(left) > size(right)) {
                swap(left, right);
            }
        }
        return result + 2;  // modified
    }

    int calc_time(int time, int change, int dist) {
        int result = 0;
        while (dist--) {
            if (result / change % 2) {
                result = (result / change + 1) * change;
            }
            result += time;
        }
        return result;
    }
};
