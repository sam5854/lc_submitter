// Time:  O(logn)
// Space: O(1)
// Iterative solution.

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        long long abs_n = abs(static_cast<long long>(n));
        while (abs_n > 0) {
            if (abs_n & 1) {
                result *= x;
            }
            abs_n >>= 1;
            x *= x;
        }
        return n < 0 ? 1 / result : result;
    }
};
