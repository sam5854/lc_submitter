// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int result = 1;
        for (int i = 0, cnt = 1; i < n - 1; ++i) {
            cnt *= 9 - i;
            result += cnt;
        }
        return 1 + 9 * result;
    }
};
