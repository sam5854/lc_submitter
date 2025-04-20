// Time:  O(nlogk + n * sqrt(k))
// Space: O(n + sqrt(k)), number of factors of k is at most sqrt(k)
// math, number theory

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> idxs;
        for (int i = 0; i < size(nums); ++i) {
            idxs[nums[i]].emplace_back(i);
        }
        int result = 0;
        for (const auto& [_, idx] : idxs) {
            unordered_map<int, int> gcds;
            for (const auto& i : idx) {
                const int gcd_i = gcd(i, k);
                for (const auto& [gcd_j, cnt] : gcds) {
                    if (gcd_i * gcd_j % k == 0) {
                        result += cnt;
                    }
                }
                ++gcds[gcd_i];
            }
        }
        return result;
    }
};
