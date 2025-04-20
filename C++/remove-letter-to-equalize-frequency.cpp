// Time:  O(n)
// Space: O(1)
// freq table, edge cases

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26);
        for (const auto& c : word) {
            ++cnt[c - 'a'];
        }
        unordered_map<int, int> cnt2;
        for (const auto& c : cnt) {
            if (c) {
                ++cnt2[c];
            }
        }
        if (size(cnt2) > 2) {
            return false;
        }
        if (size(cnt2) == 1) {
            return cbegin(cnt2)->first == 1 || cbegin(cnt2)->second == 1;
        }
        int a = cbegin(cnt2)->first;
        int b = next(cbegin(cnt2))->first;
        if (a > b) {
            swap(a, b);
        }
        return (a == 1 && cnt2[a] == 1) || (a + 1 == b && cnt2[b] == 1);
    }
};
