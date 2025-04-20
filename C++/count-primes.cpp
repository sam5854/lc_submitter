// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countPrimes(int n) {
        return size(linear_sieve_of_eratosthenes(n - 1));
    }

private:
    vector<int64_t> linear_sieve_of_eratosthenes(int64_t n) {  // Time: O(n), Space: O(n)
        vector<int64_t> spf(n + 1, -1);
        vector<int64_t> primes;
        for (int64_t i = 2; i <= n; ++i) {
            if (spf[i] == -1) {
                spf[i] = i;
                primes.emplace_back(i);
            }
            for (const auto& p : primes) {
                if (i * p > n || p > spf[i]) {
                    break;
                }
                spf[i * p] = p;
            }
        }
        return primes;
    }
};
