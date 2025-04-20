// Time:  O(n * k), k = max(cnt for _, cnt in requirements)
// Space: O(n + k)
// knapsack dp, combinatorics, sliding window, two pointers

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        static const int MOD = 1e9 + 7;

        const auto& addmod = [&](const auto& a, const auto& b) {
            return (a + b) % MOD;
        };
        const auto& submod = [&](const auto& a, const auto& b) {
            return ((a - b) % MOD + MOD) % MOD;
        };

        vector<int> lookup(n, -1);
        for (const auto& r : requirements) {
            lookup[r[0]] = r[1];
        }
        vector<int> dp = {1};
        for (int i = 0, prev = 0; i < n; ++i) {
            if (lookup[i] != -1) {
                dp = { accumulate(cbegin(dp) + max((lookup[i] - i) - prev, 0), cbegin(dp) + min(((lookup[i] + 1) - prev), static_cast<int>(size(dp))), 0, addmod) };
                prev = lookup[i];
                continue;
            }
            vector<int> new_dp(min(static_cast<int>(size(dp)) + ((i + 1) - 1), (lookup.back() + 1) - prev));
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
        return dp.back();
    }
};
