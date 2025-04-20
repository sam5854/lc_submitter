// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string lastSubstring(string s) {
        int left = 0, right = 1, l = 0;
        while (right + l < size(s)) {
            if (s[left + l] == s[right + l]) {
                ++l;
                continue;
            }
            if (s[left + l] > s[right + l]) {
                right += l + 1;
            } else {
                left = max(right, left + l + 1);
                right = left + 1;
            }
            l = 0;
        }
        return s.substr(left);
    }
};
