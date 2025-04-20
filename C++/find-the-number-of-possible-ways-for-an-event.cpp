// Time:  precompute: O(max_n^2 + max_y * min(max_n, max_x))
//        runtime:    O(min(n, x))
// Space: O(max_n^2 + max_y * min(max_n, max_x))
// dp, combinatorics

class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        init();
        int result = 0;
        for (int i = 1; i <= min(n, x); ++i) {
            result = (result + (((static_cast<int64_t>(NCR[x][i]) * DP[n][i]) % MOD) * POW[y][i]) % MOD) % MOD;
        }
        return result;
    }
};
