// Time:  O(n * l)
// Space: O(1)
// freq table

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        vector<int> prev;
        for (const auto& x : words) {
            vector<int> cnt(26);
            for (const auto& c : x) {
                ++cnt[c - 'a'];
            }
            if (!empty(prev) && prev == cnt) {
                continue;
            }
            prev = move(cnt);
            result.emplace_back(x);
        }
        return result;
    }
};
