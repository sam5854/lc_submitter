// Time:  O(logn) = O(1)
// Space: O(1)
// Only using integer type.

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle corner case.
        if (dividend == numeric_limits<int>::min() && divisor == -1) {
            return numeric_limits<int>::max();
        }

        int a = dividend > 0 ? -dividend : dividend;
        int b = divisor > 0 ? -divisor : divisor;

        int shift = 0;
        while (b << shift < 0 && shift < 32) {
            ++shift;
        }
        shift -= 1;

        int result = 0;
        while (shift >= 0) {
            if (a <= b << shift) {
                a -= b << shift;
                result += 1 << shift;
            }
            --shift;
        }

        result =  (dividend ^ divisor) >> 31 ? -result : result;
        return result;
    }
};
