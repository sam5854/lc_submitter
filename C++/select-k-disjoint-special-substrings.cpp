// Time:  O(n + 26^3)
// Space: O(26)
// hash table, sort, greedy

class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        const auto& erase_overlap_intervals = [](auto& intervals) {
            sort(begin(intervals), end(intervals), [](const auto& a, const auto& b) { return a[1] < b[1]; });
            int result = 0, right = numeric_limits<int>::min();
            for (const auto& x : intervals) {
                if (x[0] <= right) {
                    ++result;
                } else {
                    right = x[1];
                }
            }
            return result;
        };

        vector<int> cnt(26), lookup1(26, -1), lookup2(26, -1);
        for (int i = 0; i < size(s); ++i) {
            ++cnt[s[i] - 'a'];
            if (lookup1[s[i] - 'a'] == -1) {
                lookup1[s[i] - 'a'] = i;
            }
            lookup2[s[i] - 'a'] = i;
        }
        vector<vector<int>> intervals;
        for (const auto& i : lookup1) {
            if (i == -1) {
                continue;
            }
            for (const auto& j : lookup2) {
                if (j == -1 || i > j) {
                    continue;
                }
                int total = 0;
                for (int c = 0; c < size(cnt); ++c) {
                    if (i <= lookup1[c] && lookup1[c] <= lookup2[c] && lookup2[c] <= j) {
                        total += cnt[c];
                    }
                }
                if (total == j - i + 1 && total < size(s)) {
                    intervals.emplace_back(vector<int>{i, j});
                }
            }
        }
        return size(intervals) - erase_overlap_intervals(intervals) >= k;
    }
};
