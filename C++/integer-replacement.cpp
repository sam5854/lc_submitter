// Time:  O(logn)
// Space: O(1)
// Iterative solution.

class Solution {
public:
    int integerReplacement(int n) {
        if (n == 2147483647) {
            return 2 + integerReplacement(n / 2 + 1);
        }

        int result = 0;
        while (n != 1) {
            const auto b = n & 3;
            if (n == 3) {
                --n;
            } else if (b == 3) {
                ++n;
            } else if (b == 1) {
                --n;
            } else {
                n /= 2;
            }
            ++result;
        }
        return result;
    }
};
