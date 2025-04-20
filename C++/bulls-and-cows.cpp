// Time:  O(n)
// Space: O(10) = O(1)
// One pass solution.

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> lookup;
        int A = 0, B = 0;
        for (int i = 0; i < size(secret); ++i) {
            const char s = secret[i];
            const char g = guess[i];
            if (s == g) {
                ++A;
            } else {
                B += int(lookup[s]++ < 0) + int(lookup[g]-- > 0);
             }
        }
        return to_string(A).append("A").append(to_string(B)).append("B");
    }
};
