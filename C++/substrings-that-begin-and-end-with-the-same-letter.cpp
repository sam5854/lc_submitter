// Time:  O(n)
// Space: O(1)

class Solution {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char, int> cnt;
        int64_t result = 0;
        for (const auto& c : s) {
            result += ++cnt[c];
        }
        return result;
    }
};
