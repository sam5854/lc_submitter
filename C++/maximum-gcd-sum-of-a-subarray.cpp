// Time:  O(nlogr), r = max(nums)
// Space: O(logr)
// number theory, dp, prefix sum

class Solution {
public:
    long long maxGcdSum(vector<int>& nums, int k) {
        int64_t result = 0;
        vector<tuple<int, int, int64_t>> dp;
        for (int64_t right = 0, prefix = 0; right < size(nums); ++right) {
            dp.emplace_back(right, nums[right], prefix);
            prefix += nums[right];
            vector<tuple<int, int, int64_t>> new_dp;
            new_dp.reserve(size(dp));
            for (const auto& [left, g, p] : dp) {  // Time: O(logr)
                const int ng = gcd(g, nums[right]);  // Total Time: O(nlogr)
                if (empty(new_dp) || get<1>(new_dp.back()) != ng) {
                    new_dp.emplace_back(left, ng, p);  // left and ng are both strictly increasing
                }
            }
            dp = move(new_dp);
            for (const auto& [left, g, p] : dp) {
                if (right - left + 1 < k) {
                    break;
                }
                result = max(result, (prefix - p) * g);
            }
        }
        return result;
    }
};
