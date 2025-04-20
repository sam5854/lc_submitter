// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n + 1 > size(dp)) {
            for (int i = size(nums); i <= n; ++i) {
                if (i % 2 == 0) {
                    nums.emplace_back(nums[i / 2]);
                } else {
                    nums.emplace_back(nums[i / 2] + nums[i / 2 + 1]);
                }
                dp.emplace_back(max(dp.back(), nums.back()));
            }
        }
        return dp[n];
    }
};
