// Time:  O(n * sqrt(n))
// Space: O(n)
// bfs, greedy

class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&](int target) {
            vector<int> total(nums);
            vector<int> cnt(size(nums));
            for (int u = 0; u < size(nums); ++u) {
                cnt[u] = size(adj[u]);
            }
            vector<int> q;
            for (int u = 0; u < size(nums); ++u) {
                if (cnt[u] == 1) {
                    q.emplace_back(u);
                }
            }
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    if (total[u] > target) {
                        return false;
                    }
                    if (total[u] == target) {
                        total[u] = 0;
                    }
                    for (const auto& v : adj[u]) {
                        total[v] += total[u];
                        if (--cnt[v] == 1) {
                            new_q.emplace_back(v);
                        }
                    }
                }
                q = move(new_q);
            }
            return true;
        };

        const int total = accumulate(cbegin(nums), cend(nums), 0);
        for (int cnt = size(nums); cnt >= 2; --cnt) {
            if (total % cnt == 0 && bfs(total / cnt)) {
                return cnt - 1;
            }
        }
        return 0;
    }
};
