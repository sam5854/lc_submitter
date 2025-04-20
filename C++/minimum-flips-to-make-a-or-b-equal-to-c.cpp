// Time:  O(5)
// Space: O(1)

class Solution {
public:
    int minFlips(int a, int b, int c) {
        return number_of_1_bits((a | b) ^ c) + number_of_1_bits(a & b & ~c);
    }

private:
    int number_of_1_bits(int n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
        n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
        n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
        return n;
    }
};
