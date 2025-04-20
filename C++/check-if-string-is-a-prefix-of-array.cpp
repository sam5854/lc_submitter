// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0, j = 0;
        for (const auto& c : s) {
            if (i == size(words) || words[i][j] != c) {
                return false;
            }
            if (++j == size(words[i])) {
                ++i;
                j = 0;
            }
        }
        return j == 0;
    }
};
