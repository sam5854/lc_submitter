// Time:  O(n + logm)
// Space: O(n)
// combinatorics, fast exponentiation

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const auto& powmod = [&](int a, int b) {
            a %= MOD;
            int64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = result * a % MOD;
                }
                a = int64_t(a) * a % MOD;
                b >>= 1;
            }
            return result;
        };

        return (nCr(n - 1, k) * (m * powmod(m - 1, (n - 1) - k) % MOD)) % MOD;
    }
};
