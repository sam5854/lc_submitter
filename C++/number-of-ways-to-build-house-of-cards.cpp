// Time:  O(n^2)
// Space: O(n)
// dp

class Solution {
public:
    int houseOfCards(int n) {
        vector<int> dp(n + 1);  // dp[i]: number of ways with i cards and at most t triangles in the first row
        dp[0] = 1;
        for (int t = 1; t <= (n + 1) / 3; ++t) {
            for (int i = n; i >= 3 * t - 1; --i) {
                dp[i] += dp[i - (3 * t - 1)];
            }
        }
        return dp[n];
    }
};
