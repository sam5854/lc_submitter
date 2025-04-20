// Time:  O(h * p^2), p is the number of patterns
// Space: O(p^2)
// bitmask, backtracking, dp

class Solution {
public:
    int buildWall(int height, int width, vector<int>& bricks) {
        static const int MOD = 1e9 + 7;
        vector<int> patterns;
        unordered_set<int> lookup;
        backtracking(height, width, bricks, 0, 0, &lookup, &patterns);
        vector<vector<int>> adj(size(patterns));
        for (int i = 0; i < size(patterns); ++i) {
            for (int j = 0; j < size(patterns); ++j) {
                if (!(patterns[i] & patterns[j])) {
                    adj[i].emplace_back(j);
                }
            }
        }
        vector<vector<int>> dp = {vector<int>(size(patterns), 1), vector<int>(size(patterns), 0)};
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < size(patterns); ++j) {
                dp[(i + 1) % 2][j] = 0;
                for (const auto& k : adj[j]) {
                    dp[(i + 1) % 2][j] = (dp[(i + 1) % 2][j] + dp[i % 2][k]) % MOD;
                }
            }
        }
        return accumulate(cbegin(dp[(height - 1) % 2]), cend(dp[(height - 1) % 2]), 0,
                          [](const auto& total, const auto& x) {
                              return (total + x) % MOD;
                          });  // Time: O(p)
    }

private:
    void backtracking(
        int height, int width, const vector<int>& bricks,
        int total, int mask,
        unordered_set<int> *lookup,
        vector<int> *patterns) {

        if (lookup->count(mask)) {
            return;
        }
        lookup->emplace(mask);
        if (total >= width) {
            if (total == width) {
                patterns->emplace_back(mask ^ (1 << width));
            }
            return;
        }
        for (const auto& x : bricks) {
            backtracking(height, width, bricks, total + x, mask | (1 << (total + x)), lookup, patterns);
        }
    }
};
