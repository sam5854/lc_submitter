// Time:  O(n)
// Space: O(1)
// string, freq table

class Solution {
public:
    string greatestLetter(string s) {
        vector<int> cnt(52);
        for (const auto& c : s) {
            ++cnt[c - 'A' < 26 ? c - 'A' : c - 'a' + 26];
        }
        for (int i = 25; i >= 0; --i) {
            if (cnt[i] && cnt[i + 26]) {
                return string(1, i + 'A');
            }
        }
        return "";
    }
};
