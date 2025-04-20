// Time:  O(logn)
// Space: O(1)
// math

class Solution {
public:
    int countEven(int num) {
        const auto& parity = [](int x) {
            int result = 0;
            for (; x; x /= 10) {
                result += x % 10;
            }
            return result % 2;
        };
        return (num - parity(num)) / 2;
    }
};
