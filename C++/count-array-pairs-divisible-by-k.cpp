// Time:  O(nlogk + sqrt(k)^2) = O(nlogk + k)
// Space: O(sqrt(k)), number of factors of k is at most sqrt(k)
// math, number theory

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int64_t, int64_t> cnt;
        for (const auto& x : nums) {
            ++cnt[gcd(x, k)];
        }
        int64_t result = 0;
        for (const auto& [x, c1] : cnt) {
            for (const auto& [y, c2] : cnt) {
                if (x > y || x * y % k) {
                    continue;
                }
                result += (x != y) ? c1 * c2 : c1 * (c1 - 1) / 2;
            }
        }
        return result;
    }
};
