// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numberOfWays(int num_people) {
        static const int MOD = 1e9 + 7;
        int n = num_people / 2;
        return 1ULL * nCr(2 * n, n, MOD) * inv(n + 1, MOD) % MOD;  // Catalan number
    }
    
private:
    int nCr(int n, int k, int m) {
        if (n - k < k) {
            return nCr(n, n - k, m);
        }
        uint64_t result = 1;
        for (int i = 1; i <= k; ++i) {
            result = (result * (n - k + i) % m) * inv(i, m) % m;
        }
        return result;
    }
    
    int inv(int x, int m) {  // Euler's Theorem
        return pow(x, m - 2, m);
    }

    int pow(uint64_t a, int b, int m) {  // O(logMOD) = O(1)
        a %= m;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }
};
