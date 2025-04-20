// Time:  O(logn)
// Space: O(1)
// reference: https://en.wikipedia.org/wiki/Gray_code

class Solution {
public:
    int minimumOneBitOperations(int n) {
        // [observation]
        // n    f(n)
        // 000    0
        // 001    1
        // 011    2
        // 010    3
        // 110    4
        // 111    5
        // 101    6
        // 100    7
        // f(0XX...X) + f(1XX...X) = f(100...0) implies n is a gray code
        // => f(n) is actually the inverse of gray code
        return gray_to_binary(n);
    }

private:
    int gray_to_binary(int n) {
        int result = 0;
        for (; n > 0; n >>= 1) {
            result ^= n;
        }
        return result;
    }
};
