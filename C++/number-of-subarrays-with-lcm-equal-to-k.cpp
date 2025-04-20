// Time:  O(n * sqrt(k) * logk)
// Space: O(sqrt(k))
// dp

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> dp;
        for (const auto& x: nums) {
            unordered_map<int, int> new_dp;
            if (k % x == 0) {
                ++dp[x];
                for (const auto& [l, cnt] : dp) {
                    new_dp[lcm(l, x)] += cnt;
                }
            }
            dp = new_dp;
            result += dp[k];
        }
        return result;
    }
};
