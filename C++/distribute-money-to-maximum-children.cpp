// Time:  O(1)
// Space: O(1)
// greedy

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children * 1) {
            return -1;
        }
        money -= children * 1;
        const int q = money / 7, r = money % 7;
        return min(q, children) - static_cast<int>(q > children || (q == children && r != 0) || (q == children - 1 && r == 3));
    }
};
