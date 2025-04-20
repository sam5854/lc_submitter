// Time:  O(n^2)
// Space: O(n)
// iterative dfs

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        const auto& check = [](int64_t x1, int64_t y1, int64_t r1, int64_t x2, int64_t y2, int64_t r2) {
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
        };

        const auto& iter_dfs = [&]() {
            vector<char> lookup(size(circles));
            vector<char> dst(size(circles));
            vector<int> stk;
            for (int u = 0; u < size(circles); ++u) {
                const int x = circles[u][0], y = circles[u][1], r = circles[u][2];
                if (x - r <= 0 || y + r >= Y) {
                    lookup[u] = true;
                    stk.emplace_back(u);
                }
                if (x + r >= X || y - r <= 0) {
                    dst[u] = true;
                }
            }
            while (!empty(stk)) {
                const int u = stk.back(); stk.pop_back();
                if (dst[u]) {
                    return true;
                }
                const int x1 = circles[u][0], y1 = circles[u][1], r1 = circles[u][2];
                for (int v = 0; v < size(circles); ++v) {
                    const int x2 = circles[v][0], y2 = circles[v][1], r2 = circles[v][2];
                    if (lookup[v] || !check(x1, y1, r1, x2, y2, r2)) {
                        continue;
                    }
                    lookup[v] = true;;
                    stk.emplace_back(v);
                }
            }
            return false;
        };

        return !iter_dfs();
    }
};
