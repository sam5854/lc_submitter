// Time:  O(n * k)
// Space: O(k)
// knapsack dp, combinatorics, sliding window, two pointers

class Solution {
public:
    int kInversePairs(int n, int k) {
        static const int MOD = 1e9 + 7;

        const auto& addmod = [&](const auto& a, const auto& b) {
            return (a + b) % MOD;
        };
        const auto& submod = [&](const auto& a, const auto& b) {
            return ((a - b) % MOD + MOD) % MOD;
        };

        vector<int> dp = {1};
        for (int i = 0; i < n; ++i) {
            vector<int> new_dp(min(static_cast<int>(size(dp)) + ((i + 1) - 1), k + 1));
            for (int j = 0; j < size(new_dp); ++j) {
                new_dp[j] = j < size(dp) ? dp[j] : 0;
                if (j - 1 >= 0) {
                    new_dp[j] = addmod(new_dp[j], new_dp[j - 1]);
                }
                if (j - (i + 1) >= 0) {
                    new_dp[j] = submod(new_dp[j], dp[j - (i + 1)]);
                }
            }
            dp = move(new_dp);
        }
        return k < size(dp) ? dp[k] : 0;
    }
};
