// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool canConstruct(string s, int k) {
        bitset<26> odd;
        for (const auto& c : s) {
            odd.flip(c - 'a');
        }
        return odd.count() <= k && k <= s.length();
    }
};
