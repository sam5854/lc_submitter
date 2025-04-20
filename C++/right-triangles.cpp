// Time:  O(n * m)
// Space: O(min(n, m))
// combinatorics

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        const int n = size(grid), m = size(grid[0]);
        const auto& get = [&](int i, int j) {
            return n < m ? grid[i][j] : grid[j][i];
        };

        const int mn = min(n, m), mx = max(n, m);
        vector<int> cnt1(mn);
        for (int i = 0; i < mn; ++i) {
            for (int j = 0; j < mx; ++j) {
                cnt1[i] += get(i, j);
            }
        }
        int64_t result = 0;
        for (int j = 0; j < mx; ++j) {
            int cnt2 = 0;
            for (int i = 0; i < mn; ++i) {
                cnt2 += get(i, j);
            }
            for (int i = 0; i < mn; ++i) {
                if (get(i, j)) {
                    result += (cnt1[i] - 1ll) * (cnt2 - 1ll);
                }
            }
        }
        return result;
    }
};
