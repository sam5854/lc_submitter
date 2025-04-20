// Time:  O(n + 26)
// Space: O(26)
// counting sort, greedy

class Solution {
public:
    string makeAntiPalindrome(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        if (ranges::max(cnt) > size(s) / 2) {
            return "-1";
        }
        string result(size(s), 0);
        for (int i = 0, j = 0; i < size(cnt); ++i) {
            for (int _ = 0; _ < cnt[i]; ++_) {
                result[j++] = 'a' + i;
            }
        }
        int l = 0;
        for (; l <= (size(s) / 2) / 2; ++l) {
            if (result[size(s) / 2 + l] != result[size(s) / 2 - 1]) {
                break;
            }
        }
        if (l) {
            for (int i = 0; i < cnt[result[size(s) / 2 - 1] - 'a'] - l; ++i) {
                swap(result[size(s) / 2 + i], result[size(s) / 2 + i + l]);
            }
        }
        return result;
    }
};
