// Time:  precompute: O(sqrt(MAX_N))
//        runtime:    O(m + nlog(logn)), m = len(nums), n = max(nums)
// Space: O(sqrt(MAX_N))
// number theory

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> result;
        for (auto x : unordered_set<int>(cbegin(nums), cend(nums))) {  // Time: O(n/p1 + n/p2 + ... + n/pk) = O(n * (1/p1 + 1/p2 + ... + 1/pk)) = O(nlog(logn))
            for (const auto& p : PRIMES) {
                if (p > x) {
                    break;
                }
                if (x % p) {
                    continue;
                }
                result.emplace(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
            if (x != 1) {  // x is a prime
                result.emplace(x);
            }
        }
        return size(result);
    }
};
