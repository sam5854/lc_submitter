// Time:  O(n)
// Space: O(1)
// dp

class Solution {
public:
    int minimumTime(string s) {
        int left = 0;
        int result = left + (size(s) - 0);
        for (int i = 1; i <= size(s); ++i) {
            left = min(left + 2 * (s[i - 1] == '1'), i);
            result = min(result, left + static_cast<int>(size(s)) - i);
        }
        return result;
    }
};
