// Time:  precompute:  O(sqrt(r))
//        runtime:     O(logr + log(sqrt(r))) = O(logr)
// Space: O(sqrt(r))
// number theory, binary search

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        const auto& count = [](int x) {
            return x - distance(cbegin(PRIMES), upper_bound(cbegin(PRIMES), cend(PRIMES), sqrt(x)));
        };

        return count(r) - count(l - 1);
    }
};
