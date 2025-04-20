// Time:  O(n^2 * k), n = len(str(high))
// Space: O(n^2 * k)
// memoization (faster but more space)

class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        enum {TIGHT, UNTIGHT, UNBOUND};

        const auto& to_digits = [](int x) {
            vector<int> result;
            for (; x; x /= 10) {
                result.emplace_back(x % 10);
            }
            reverse(begin(result), end(result));
            return !empty(result) ? result : vector<int>{0};
        };

        const auto& f = [&](int x) {
            const auto& digits = to_digits(x);
            vector<vector<vector<vector<int>>>> lookup(size(digits), vector<vector<vector<int>>>(3, vector<vector<int>>(2 * size(digits) + 1, vector<int>(k, -1))));
            function<int (int, int, int, int)> memoization = [&](int i, int state, int diff, int total) {
                if (i == size(digits)) {
                    return static_cast<int>(state != UNBOUND && diff == size(digits) && total == 0);
                }
                if (lookup[i][state][diff][total] == -1) {
                    int result = static_cast<int>(i != 0 && diff == size(digits) && total == 0);  // count if the beautiful integer x s.t. len(str(x)) < len(digits)
                    for (int d = (i == 0) ? 1 : 0; d <= 9; ++d) {
                        int new_state = state;
                        if (state == TIGHT && d != digits[i]) {
                            new_state = d < digits[i] ? UNTIGHT : UNBOUND;
                        }
                        const int new_diff = diff + (d % 2 == 0 ? 1 : -1);
                        const int new_total = (total * 10 + d) % k;
                        result += memoization(i + 1, new_state, new_diff, new_total);
                    }
                    lookup[i][state][diff][total] = result;
                }
                return lookup[i][state][diff][total];
            };
    
            return memoization(0, TIGHT, size(digits), 0);
        };

        return f(high) - f(low - 1);
    }
};
