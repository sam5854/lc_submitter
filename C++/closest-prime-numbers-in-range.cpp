// Time:  precompute:  O(MAX_N * log(MAX_N))
//        runtime:     O(log(MAX_N))
// Space: O(MAX_N)
// Template:
// https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/booking-concert-tickets-in-groups.cpp
// number theory, segment tree

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int i = distance(cbegin(PRIMES), lower_bound(cbegin(PRIMES), cend(PRIMES), left));
        int j = distance(cbegin(PRIMES), upper_bound(cbegin(PRIMES), cend(PRIMES), right)) - 1;
        if (i > j - 1) {
            return {-1, -1};
        }
        const auto& result = ST.query(i, j - 1);
        return {result[1], result[2]};
    }
};
