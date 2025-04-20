// Time:  O(n)
// Space: O(1)
// combinatorics, fast exponentiation

class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        // 2^(odd-1)*2^even = 2^(len(nums)-1)
        return any_of(cbegin(nums), cend(nums), [](const auto& x) {
            return x % 2 == 1;
        }) ? powmod(2, size(nums) - 1, MOD) : 0;
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
