// Time:  O(n^2)
// Space: O(n)
// dfs with stack

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<int> left(size(nums)), right(size(nums));
        const auto& is_ancestor = [&](int a, int b) {
            return left[a] <= left[b] && right[b] <= right[a];
        };

        const auto& iter_dfs = [&]() {
            int cnt = 0;
            vector<tuple<int, int, int>> stk;
            stk.emplace_back(1, 0, -1);
            while (!empty(stk)) {
                const auto [step, u, p] = stk.back(); stk.pop_back();
                if (step == 1) {
                    left[u] = cnt++;
                    stk.emplace_back(2, u, p);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u);
                    }
                } else if (step == 2) {
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        nums[u] ^= nums[v];
                    }
                    right[u] = cnt;
                }
            }
        };

        iter_dfs();
        int result = numeric_limits<int>::max();
        for (int i = 1; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                int a, b, c;
                if (is_ancestor(i, j)) {
                    tie(a, b, c) = tuple(nums[0] ^ nums[i], nums[i] ^ nums[j], nums[j]);
                } else if (is_ancestor(j, i)) {
                    tie(a, b, c) = tuple(nums[0] ^ nums[j], nums[j] ^ nums[i], nums[i]);
                } else {
                    tie(a, b, c) = tuple(nums[0] ^ nums[i] ^ nums[j], nums[i], nums[j]);
                }
                result = min(result, max({a, b, c}) - min({a, b, c}));
            }
        }
        return result;
    }
};
