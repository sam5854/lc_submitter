// Time:  O(n + (logn)^2) = O(n)
// Space: O(n + logn) = O(n)
// bit manipulation, freq table, combinatorics

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        const auto& bit_length = [](int x) {
            return x != 0 ? 32 - __builtin_clz(x) : 1;
        };

        const int mx = *max_element(cbegin(nums), cend(nums));
        vector<int64_t> cnt(bit_length(mx) + 1);
        unordered_set<int> lookup;
        for (const auto& x : nums) {
            if (lookup.count(x)) {
                continue;
            }
            lookup.emplace(x);
            ++cnt[__builtin_popcount(x)];
        }
        int64_t result = 0;
        for (int i = 1; i < size(cnt); ++i) {
            for (int j = 1; j < size(cnt); ++j) {
                if (i + j >= k) {
                    result += cnt[i] * cnt[j];
                }
            }
        }
        return result;
    }
};
