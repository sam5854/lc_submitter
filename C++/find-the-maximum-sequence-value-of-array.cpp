// Time:  O(n * r + r^2)
// Space: O(r)
// bitmasks, prefix sum, dp

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        static const int INF = numeric_limits<int>::max();
        static const int MAX_MASK = 127;
        
        const auto& is_submask = [](int a, int b) {
            return (a | b) == b;
        };
    
        const auto& dp = [&](int d, int npos) {
            vector<int> result(MAX_MASK + 1, npos);
            vector<int> dp(MAX_MASK + 1, INF), cnt(MAX_MASK + 1, 0);
            const int begin = d == 1 ? 0 : size(nums) - 1;
            const int end = d == 1 ? size(nums) : -1;
            for (int i = begin ; i != end; i += d) {
                dp[nums[i]] = 1;
                for (int mask = 0; mask <= MAX_MASK; ++mask) {
                    if (is_submask(nums[i], mask)) {
                        ++cnt[mask];
                    }
                    if (dp[mask] != INF) {
                        dp[mask | nums[i]] = min(dp[mask | nums[i]], dp[mask] + 1);
                    }
                }
                for (int mask = 0; mask < MAX_MASK + 1; ++mask) {
                    if (cnt[mask] >= k && dp[mask] <= k && result[mask] == npos) {
                        result[mask] = i;
                    }
                }
            }
            return result;
        };

        const auto& left = dp(1, size(nums));
        const auto& right = dp(-1, -1);
        for (int result = MAX_MASK; result >= 0; --result) {
            for (int l = 1; l <= MAX_MASK; ++l) {
                if (left[l] < right[result ^ l]) {
                    return result;
                }
            }
        }
        return 0;
    }
};
