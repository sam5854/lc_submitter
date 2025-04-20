// Time:  O((m * n) * (m + n) / 32)
// Space: O(n * (m + n) / 32)
// dp with bitsets

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if ((size(grid) + size(grid[0]) - 1) % 2 == 1) {
            return false;
        }
        vector<bitset<100>> dp(size(grid[0]) + 1);
        for (int i = 0; i < size(grid); ++i) {
            dp[0][0] = !i;
            for (int j = 0; j < size(grid[0]); ++j) {
                dp[j + 1] = (grid[i][j] == '(') ? (dp[j] | dp[j + 1]) << 1: (dp[j] | dp[j + 1]) >> 1;
            }
        }
        return dp.back()[0];
    }
};
