// Time:  O(n^2)
// Space: O(n)
// dp

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        vector<int64_t> dp(size(nums));  // dp[j] at l: # of tuple (i, j, k) s.t. i < j < k < l and nums[i] < nums[k] < nums[j]
        int64_t result = 0;
        for (int l = 0; l < size(nums); ++l) {
            int cnt = 0;
            for (int j = 0; j < l; ++j) {
                if (nums[j] < nums[l]) {
                    ++cnt;
                    result += dp[j];
                } else if (nums[j] > nums[l]) {
                    dp[j] += cnt;
                }
            }
        }
        return result;
    }
};
