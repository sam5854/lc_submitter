// Time:  O(n^2)
// Space: O(n)
// dp

class Solution {
public:
    int deleteString(string s) {
        if (all_of(cbegin(s), cend(s), [&](const auto& x) { return x == s[0]; })) {
            return size(s);
        }
        vector<vector<int>> dp2(2, vector<int>(size(s) + 1));  // dp2[i%2][j]: max prefix length of s[i:] and s[j:]
        vector<int> dp(size(s), 1);  // dp[i]: max operation count of s[i:]
        for (int i = size(s) - 2; i >= 0; --i) {
            for (int j = i + 1; j < size(s); ++j) {
                dp2[i % 2][j] = (s[j] == s[i]) ? dp2[(i + 1) % 2][j + 1] + 1 : 0;
                if (dp2[i % 2][j] >= j - i) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[0];
    }
};
