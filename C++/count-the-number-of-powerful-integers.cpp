// Time:  O(logf)
// Space: O(1)
// math, combinatorics

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        const auto& count = [&](int64_t x) {
            const auto& length = [](int64_t x) {
                int result = 0;
                for (; x; x /= 10) {
                    ++result;
                }
                return result;
            };

            int64_t result = 0;
            const int n = length(x);
            const int l = n - size(s);
            int64_t base = powl(10, n);
            int i = 0;
            for (int64_t cnt = powl(limit + 1, l); i < l; ++i) {
                base /= 10;
                const int curr = x / base % 10;
                cnt /= limit + 1;
                result += (min(curr - 1, limit) - 0 + 1) * cnt;
                if (curr > limit) {
                    break;
                }
            }
            if (i == l) {
                if (x % base >= stoll(s)) {
                    ++result;
                }
            }
            return result;
        };

        return count(finish) - count(start - 1);
    }
};
