// Time:  O(n * w * l)
// Space: O(l)
// dp

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int l = 0;
        for (const auto& w : words) {
            l = max(l, static_cast<int>(size(w)));
        }
        vector<int> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(target); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            for (int j = 0; j < size(words); ++j) {
                if (target.substr(i, size(words[j])) == words[j]) {
                    dp[(i + size(words[j])) % size(dp)] = min(dp[(i + size(words[j])) % size(dp)], dp[i % size(dp)] + costs[j]);
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(target) % size(dp)] != INF ? dp[size(target) % size(dp)] : -1;
    }
};
