// Time:  O(nlogn)
// Space: O(1)
// math, sort

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;
        sort(begin(nums), end(nums));
        auto total = accumulate(cbegin(nums), cend(nums), 0ll);
        int i = size(nums) - 1;
        for (; i >= 0; --i) {
            if (nums[i] * static_cast<int64_t>(i + 1) - total <= k) {
                break;
            }
            total -= nums[i];
        }
        const int q = (k + total) / (i + 1);
        const int r = (k + total) % (i + 1);
        return ((static_cast<uint64_t>(powmod(q, (i + 1) - r, MOD)) * powmod(q + 1, r, MOD) % MOD) *
                accumulate(cbegin(nums) + i + 1, cend(nums), 1ull,
                          [=](const auto& total, const auto& x) {
                              return total * x % MOD;
                          })) % MOD;
    }

private:
    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
        a %= mod;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = result * a % mod;
            }
            a = uint64_t(a) * a % mod;
            b >>= 1;
        }
        return result;
    }
};
