// Time:  O(logn)
// Space: O(1)
// combinatorics, principle of inclusion-exclusion

class Solution {
public:
    int stringCount(int n) {
        static const int MOD = 1e9 + 7;
        const auto& powmod = [](uint64_t a, uint64_t b, uint64_t mod) {
            a %= mod;
            int64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (result * a % mod);
                }
                a = (a * a % mod);
                b >>= 1;
            }
            return result;
        };
    
        return  ((powmod(26, n, MOD) - 
                 (25 + 25 + 25 + n) * powmod(25, n - 1, MOD) +                   // no l, t, e, ee
                 (24 + 24 + 24 + n + n + 0) * powmod(24, n - 1, MOD) -           // no l|t, l|e, t|e, l|ee, t|ee, e|ee
                 (23 + n + 0 + 0) * powmod(23, n - 1, MOD)) % MOD + MOD) % MOD;  // no l|t|e, l|t|ee, l|e|ee, t|e|ee    
    }
};
