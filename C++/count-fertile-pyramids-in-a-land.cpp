// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        return count(grid, false) + count(grid, true);
    }

private:
    int count(const vector<vector<int>>& grid, int reverse) {
        auto get_grid = [&grid, &reverse](int i, int j) {
            return reverse ? grid[size(grid) - 1 - i][j] : grid[i][j];
        };

        int result = 0;
        vector<int> dp(size(grid[0]));
        for (int i = 1; i < size(grid); ++i) {
            vector<int> new_dp(size(grid[0]));
            for (int j = 1; j + 1 < size(grid[0]); ++j) {
                if (get_grid(i, j) == get_grid(i - 1, j - 1) &&
                    get_grid(i - 1, j - 1) == get_grid(i - 1, j) &&
                    get_grid(i - 1, j) == get_grid(i - 1, j + 1) &&
                    get_grid(i - 1, j + 1) == 1) {
                    new_dp[j] = min(dp[j - 1], dp[j + 1]) + 1;
                }
            }
            dp = move(new_dp);
            result += accumulate(cbegin(dp), cend(dp), 0);
        }
        return result;
    }
};
