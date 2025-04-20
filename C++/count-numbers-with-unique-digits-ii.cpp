// Time:  O(logb)
// Space: O(1)
// hash table, bitmask, combinatorics

class Solution {
public:
    int numberCount(int a, int b) {
        const auto& count2 = [&](int n) {
            if (n == 0) {
                return 0;
            }
            int result = 1;
            for (int i = 0, cnt = 1; i < n - 1; ++i) {
                cnt *= 9 - i;
                result += cnt;
            }
            return 9 * result;
        };

        const auto& count = [&](int x) {
            int n = 1, base = 1;
            for (; x / (base * 10); base *= 10, ++n);
            int result = count2(n - 1);
            int lookup = 0;
            int cnt = 1;
            for (int i = 0; i < n - 1; ++i) {
                cnt *= 9 - i;
            }
            for (int i = 0; i < n; ++i, base /= 10) {
                const int d = (x / base) % 10;
                const int mask = lookup & (((1 << d) - 1) - (i == 0 ? 1 : 0));
                result += ((d - (i == 0 ? 1 : 0)) - __builtin_popcount(mask)) * cnt;
                cnt /= 9 - i;
                if (lookup & (1 << d)) {
                    break;
                }
                lookup |= 1 << d;
            }
            return result;
        };

        return count(b + 1) - count(a);
    }
};
