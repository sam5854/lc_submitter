// Time:  O(m * n)
// Space: O(m)
// dp

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<bool> dp(size(grid), true);
        int c = 0;
        for (; c < size(grid[0]) - 1; ++c) {
            vector<bool> new_dp(size(grid));
            for (int r = 0; r < size(grid); ++r) {
                if (!dp[r]) {
                    continue;
                }
                if (grid[r][c] < grid[r][c + 1]) {
                    new_dp[r] = true;
                }
                if (r - 1 >= 0 && grid[r][c] < grid[r - 1][c + 1]) {
                    new_dp[r - 1] = true;
                }
                if (r + 1 < size(grid) && grid[r][c] < grid[r + 1][c + 1]) {
                    new_dp[r + 1] = true;
                }
            }
            dp = move(new_dp);
            if (!accumulate(cbegin(dp), cend(dp), 0)) {
                break;
            }
        }
        return c;
    }
};
