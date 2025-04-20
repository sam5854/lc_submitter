// Time:  O(max(logk, x) * log((logk) / x))
// Space: O((logk) / x)
// bit manipulation, binary search, combinatorics

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        const auto& binary_search_right = [](long long left, long long right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        long long result = 0, prefix_cnt = 0;
        vector<long long> lookup = {0};
        for (int i = 0; (lookup.back() << x) + (1ll << (i + x - 1)) <= k; i += x) {
            lookup.emplace_back((lookup.back() << x) + (1ll << (i + x - 1)));
        }
        const auto& count = [&](int l) {
            return (prefix_cnt << (x * l)) + lookup[l];
        };

        while (k >= prefix_cnt) {
            const auto& l = binary_search_right(1, size(lookup) - 1, [&](int l) {
                return count(l) <= k;
            });
            long long cnt = count(l);
            int i = x * l;
            const int c = min(cnt ? static_cast<int>(__lg(k / cnt)) : x - 1, x - 1);
            cnt <<= c;
            i += c;
            k -= cnt;
            result += 1ll << i;
            if ((i + 1) % x == 0) {
                ++prefix_cnt;
            }
        }
        return result - 1;
    }
};
