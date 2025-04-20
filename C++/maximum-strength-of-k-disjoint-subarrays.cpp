// Time:  O(k * n)
// Space: O(n)
// dp, greedy, kadane's algorithm

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        static const int64_t NEG_INF = numeric_limits<int64_t>::min();

        vector<int64_t> dp(size(nums) + 1);
        for (int64_t i = 0; i < k; ++i) {
            vector<int64_t> new_dp(size(nums) + 1, NEG_INF);
            for (int64_t j = 0; j < size(nums); ++j) {
                const auto& mx = max(new_dp[j], dp[j]);
                if (mx != NEG_INF) {
                    new_dp[j + 1] = mx + nums[j] * (k - i) * (i % 2 == 0 ? 1 : -1);
                }
            }
            dp = move(new_dp);
        }
        return ranges::max(dp);
    }
};
