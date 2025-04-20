// Time:  O(w * b * 2^b)
// Space: O(w * b * 2^b)
// if w = b, we can even apply Hungarian algorithm (see https://en.wikipedia.org/wiki/Hungarian_algorithm),
// it can be improved to O(w^3), see https://github.com/t3nsor/codebook/blob/master/bipartite-mincost.cpp

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<double>> dp(2,
                                  vector<double>(1 << bikes.size(),
                                                 numeric_limits<double>::infinity()));
        dp[0][0] = 0;
        for (int i = 0; i < workers.size(); ++i) {
            dp[(i + 1) % 2] = vector<double>(1 << bikes.size(),
                                             numeric_limits<double>::infinity());
            for (int j = 0; j < bikes.size(); ++j) {
                for (int taken = 0; taken < (1 << bikes.size()); ++taken) {
                    if (taken & (1 << j)) {
                        continue;
                    }
                    dp[(i + 1) % 2][taken | (1 << j)] =
                        min(dp[(i + 1) % 2][taken | (1 << j)],
                            dp[i % 2][taken] + manhattan(workers[i], bikes[j]));
                }
            }
        }
        return *min_element(dp[workers.size() % 2].cbegin(), dp[workers.size() % 2].cend());
    }

private:
    int manhattan(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
