// Time:  O(n)
// Space: O(n)
// KMP Algorithm optimized from Solution2

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        string rev_s(s.crbegin(), s.crend());
        // Assume s is (Palindrome)abc,
        // A would be (Palindrome)abc#cba(Palindrome).
        string A = s + '#' + rev_s;
        auto prefix = getPrefix(A);
        // The index prefix.back() of A would be:
        // (Palindrome)abc#cba(Palindrome)
        //            ^
        // The index prefix.back() + 1 of s would be:
        // (Palindrome)abc
        //             ^
        // Get non palindrome part of s.
        string non_palindrome = s.substr(prefix.back() + 1);
        reverse(non_palindrome.begin(), non_palindrome.end());
        return non_palindrome + s;  // cba(Palindrome)abc.
    }
        
private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
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
