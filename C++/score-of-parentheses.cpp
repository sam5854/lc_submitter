// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int scoreOfParentheses(string S) {
        int result = 0, depth = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') {
                ++depth;
            } else {
                --depth;
                if (S[i - 1] == '(') {
                    result += 1 << depth;
                }
            }
        }
        return result;
    }
};
