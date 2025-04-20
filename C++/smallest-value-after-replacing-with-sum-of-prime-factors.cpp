// Time:  O(s * logn), s is the times of simulation
// Space: O(max_n^0.5)
// number theory, simulation

class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int curr = n, new_n =0;
            for (const auto& p : PRIMES) {
                if (p * p > curr) {
                    continue;
                }
                while (curr % p == 0) {
                    curr /= p;
                    new_n += p;
                }
            }
            if (curr > 1) {  // curr is a prime
                new_n += curr;
            }
            if (new_n == n) {
                break;
            }
            n = new_n;
        }
        return n;
    }
};
