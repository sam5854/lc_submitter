// Time:  O(sqrt(n))
// Space: O(sqrt(n))

class Solution {
public:
    int reinitializePermutation(int n) {
        return 1 + discrete_log(2, n / 2, n - 1);  // find min x s.t. 2^x mod (n-1) = n/2, result is x + 1
    }

private:
    // reference: https://cp-algorithms.com/algebra/discrete-log.html
    int discrete_log(int a, int b, int m) {
        a %= m, b %= m;
        int n = sqrt(m) + 1;
        int an = 1;
        for (int i = 0; i < n; ++i) {
            an = (an * 1ll * a) % m;
        }
        unordered_map<int, int> vals;
        for (int q = 0, curr = b; q <= n; ++q) {
            vals[curr] = q;
            curr = (curr * 1ll * a) % m;
        }
        for (int p = 1, curr = 1; p <= n; ++p) {
            curr = (curr * 1ll * an) % m;
            if (vals.count(curr)) {
                return n * p - vals[curr];
            }
        }
        return -1;
    }
};
