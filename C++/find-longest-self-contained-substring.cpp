// Time:  O(n + 26^3 * logn)
// Space: O(n)
// hash table, binary search

class Solution {
public:
    int maxSubstringLength(string s) {
        vector<vector<int>> idxs(26);
        for (int i = 0; i < size(s); ++i) {
            idxs[s[i] - 'a'].emplace_back(i);
        }
        const auto& check = [&](int left, int right) {
            for (const auto& x : idxs) {
                if (empty(x) || x.back() < left || x[0] > right || (left <= x[0] && x.back() <= right)) {
                    continue;
                }
                const int i = distance(cbegin(x), lower_bound(cbegin(x), cend(x), left));
                if (i != size(x) && x[i] <= right) {
                    return false;
                }
            }
            return true;
        };

        int result = -1;
        for (const auto& x : idxs) {
            if (empty(x)) {
                continue;
            }
            const int left = x[0];
            for (const auto& y : idxs) {
                if (empty(y)) {
                    continue;
                }
                const int right = y.back();
                if (left <= right && result < right - left + 1 && right - left + 1 != size(s) && check(left, right)) {
                    result = right - left + 1;
                }
            }
        }
        return result;
    }
};
