// Time:  precompute: O(max(m * n))
//        runtime:    O(1)
// Space: O(max(m * n))
// combinatorics
// reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types

class Solution {
public:
    int distanceSum(int m, int n, int k) {
        const auto& sum_n = [](int n) {
            return static_cast<int64_t>(n + 1) * n / 2;
        };

        const auto& sum_n_square = [](int n) {
            return static_cast<int64_t>(n) * (n + 1) * (2 * n + 1) / 6;
        };

        const auto& f = [&](int n) {
            // sum((d*(n-d) for d in xrange(1, n)))
            return (n * sum_n(n - 1) - sum_n_square(n - 1)); 
        };

        const auto x = mulmod(mulmod(f(n) % MOD, m), m);
        const auto y = mulmod(mulmod(f(m) % MOD, n), n);
        return mulmod(x + y, nCr(m * n - 2, k - 2));
    }
};
