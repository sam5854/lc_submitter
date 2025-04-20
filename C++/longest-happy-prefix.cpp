// Time:  O(n)
// Space: O(n)
// kmp solution

class Solution {
public:
    string longestPrefix(string s) {
        return s.substr(0, getPrefix(s).back() + 1);
    }

private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};
