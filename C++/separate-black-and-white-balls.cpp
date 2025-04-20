// Time:  O(n)
// Space: O(1)
// two pointers

class Solution {
public:
    long long minimumSteps(string s) {
        int64_t result = 0;
        for (int right = 0, left = 0; right < size(s); ++right) {
            if (s[right] != '0') {
                continue;
            }
            result += right - left++;
        }
        return result;
    }
};
