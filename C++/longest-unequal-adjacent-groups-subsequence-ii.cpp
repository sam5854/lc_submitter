// Time:  O(n^2)
// Space: O(n)
// dp, backtracing

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        const auto& check = [&](const auto& s1, const auto& s2) {
            if (size(s1) != size(s2)) {
                return false;
            }
            int cnt = 0;
            for (int k = 0; k < size(s1); ++k) {
                cnt += s1[k] != s2[k] ? 1 : 0;
                if (cnt == 2) {
                    return false;
                }
            }
            return cnt == 1;
        };

        vector<pair<int, int>> dp(n, pair(1, -1));
        int i = -1;
        for (int i = n - 1; i >= 0; --i) {
            const auto& si = words[i];
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] != groups[j] && check(words[j], si)) {
                    dp[i] = max(dp[i], pair(dp[j].first + 1, j));
                }
            }
        }
        vector<string> result;
        for (int i = distance(cbegin(dp), max_element(cbegin(dp), cend(dp)));i != -1; i = dp[i].second) {
            result.emplace_back(words[i]);
        }
        return result;
    }
};
