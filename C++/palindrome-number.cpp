// Time:  O(logx) = O(1)
// Space: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x;
        int reversed = 0;
        while (temp != 0) {
            if (isOverflow(reversed, temp % 10)) {
                return false;
            }
            reversed = reversed * 10 + temp % 10;
            temp = temp / 10;
        }
        return reversed == x;
    }

private:
    bool isOverflow(int q, int r) {
        static const int max_q = numeric_limits<int>::max() / 10;
        static const int max_r = numeric_limits<int>::max() % 10;
        return (q > max_q) || (q == max_q && r > max_r);
    }
};
