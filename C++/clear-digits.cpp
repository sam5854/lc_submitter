// Time:  O(n)
// Space: O(1)
// two pointers

class Solution {
public:
    string clearDigits(string s) {
        int j = 0;
        for (int i = 0; i < size(s); ++i) {
            if (isdigit(s[i])) {
                --j;
                continue;
            }
            s[j++] = s[i];
        }
        s.resize(j);
        return s;
    }
};
