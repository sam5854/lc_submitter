// Time:  O(n + logt)
// Space: O(1)
// freq table, greedy, prefix sum, number theory

class Solution {
public:
    string smallestNumber(string num, long long t) {
        static const vector<vector<tuple<int, int, int, int>>> LOOKUP = {
            {{0, 0, 0, 0}, {0, 1, 0, 0}},
            {{1, 0, 0, 0}, {0, 0, 0, 1}},
            {{0, 0, 1, 0}, {1, 0, 0, 1}}
        };

        const auto& count = [](int64_t x) {
            vector<int> cnt(10);
            for (int i = 2; i <= 9; ++i) {
                while (x % i == 0) {
                    x /= i;
                    ++cnt[i];
                }
                if (x == 1) {
                    return cnt;
                }
            }
            return vector<int>();
        };
    
        const auto& update = [](auto& total, auto cnt, int d) {
            for (int i = 0; i < size(cnt); ++i) {
                total[i] += d * cnt[i];
            }
        };

        const auto& diff = [](const auto& expect, const auto&total) {
            vector<int> result(10);
            for (int i = 0; i < size(expect); ++i) {
                result[i] = max(expect[i] - total[i], 0);
            }
            return result;
        };

        const auto& min_factors = [](const auto& cnt) {
            const int cnt8 = cnt[2] / 3, r2 = cnt[2] % 3;
            const int cnt9 = cnt[3] / 2, r3 = cnt[3] % 2;
            const auto& [cnt2, cnt3, cnt4, cnt6] = LOOKUP[r2][r3];
            return vector<int>{cnt2, cnt3, cnt4, cnt[5], cnt6, cnt[7], cnt8, cnt9};
        };
        
        const auto& format = [](const auto& cnt, int l) {
            string result(l, '1');
            int i = l - accumulate(cbegin(cnt), cend(cnt), 0);
            for (int x = 2; x <= 9; ++x) {
                for (int _ = 0; _ < cnt[x - 2]; ++_) {
                    result[i++] = '0' + x;
                }
            }
            return result;
        };

        const auto& expect = count(t);
        if (empty(expect)) {
            return "-1";
        }
        int i = 0;
        for (; i < size(num); ++i) {
            if (num[i] == '0') {
                break;
            }
        }
        for (; i < size(num); ++i) {
            num[i] = '1';
        }
        vector<int> total(10);
        for (const auto& x : num) {
            update(total, count(x - '0'), +1);
        }
        const auto& d = diff(expect, total);
        if (all_of(cbegin(d), cend(d), [](const auto& x) {
            return x == 0;
        })) {
            return num;
        }
        for (int i = size(num) - 1; i >= 0; --i) {
            update(total, count(num[i] - '0'), -1);
            for (int x = (num[i] - '0') + 1; x <= 9; ++x) {
                update(total, count(x), +1);
                const auto& tmp = min_factors(diff(expect, total));
                update(total, count(x), -1);
                if (accumulate(cbegin(tmp), cend(tmp), 0) > size(num) - 1 - i) {
                    continue;
                }
                num[i] = '0' + x;
                return num.substr(0, i + 1) + format(tmp, size(num) - 1 - i);
            }
        }
        const auto& result = min_factors(diff(expect, total));
        return format(result, max(static_cast<int>(size(num)) + 1, accumulate(cbegin(result), cend(result), 0)));
    }
};
