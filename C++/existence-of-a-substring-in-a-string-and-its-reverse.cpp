// Time:  O(n)
// Space: O(min(n, 26^2))
// hash table

class Solution {
public:
    bool isSubstringPresent(string s) {
        vector<vector<bool>> lookup(26, vector<bool>(26));
        for (int i = 0; i + 1 < size(s); ++i) {
            lookup[s[i] - 'a'][s[i + 1] - 'a'] = true;
        }
        for (int i = 0; i + 1 < size(s); ++i) {
            if (lookup[s[i + 1] - 'a'][s[i] - 'a']) {
                return true;
            }
        }
        return false;
    }
};
