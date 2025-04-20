// Time:  O(nlogr), r = max(max(a), max(b), max(c))
// Space: O(1)
// bit manipulation, parity

class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        const auto& count = [](const auto& a) {
            const auto& odd = accumulate(cbegin(a), cend(a), 0, [](const auto& total, const auto& x) {
                return total + (__builtin_popcount(x) & 1);
            });
            return vector<int>{static_cast<int>(size(a)) - odd, odd};
        };

        vector<vector<int>> cnt = {count(a), count(b), count(c)};
        int result = 0;
        for (int i = 0; i < 4; ++i) {
            result += cnt[0][i == 0 || i == 1 ? 0 : 1] * 
                      cnt[1][i == 0 || i == 2 ? 0 : 1] *
                      cnt[2][i == 0 || i == 3 ? 0 : 1];
        }
        return result;
    }
};
