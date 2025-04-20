// Time:  O(n)
// Space: O(n)
// dp solution

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        return count(nums, high + 1) - count(nums, low);
    }

private:
    int count(const vector<int>& nums, int x) {
        unordered_map<int, int> dp;
        for (const auto& x : nums) {
            ++dp[x];
        }
        int result = 0;
        for (; x; x >>= 1) {
            unordered_map<int, int> new_dp;
            for (auto const& [k, v] : dp) {
                new_dp[k >> 1] += v;
                if ((x & 1) == 0) {
                    continue;
                }
                if (dp.count((x ^ 1) ^ k)) {
                    result += v * dp[(x ^ 1) ^ k];  // current limit is xxxxx1*****, count xor pair with xxxxx0***** pattern
                }
            }
            dp = move(new_dp);
        }
        return result / 2;
    }
};
