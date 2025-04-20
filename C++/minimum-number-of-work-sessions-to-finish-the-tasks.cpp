// Time:  O(n * 2^n)
// Space: O(2^n)

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        // dp[mask]: min used time by choosing tasks in mask bitset
        vector<int> dp(1 << size(tasks), numeric_limits<int>::max());
        dp[0] = 0;
        for (int mask = 0; mask < size(dp) - 1; ++mask) {
            int basis = 1;
            for (auto task : tasks) {
                const int new_mask = mask | basis;
                basis <<= 1;
                if (new_mask == mask) {
                    continue;
                }
                if (dp[mask] % sessionTime + task > sessionTime) {
                    task += sessionTime - dp[mask] % sessionTime;  // take a break
                }
                dp[new_mask] = min(dp[new_mask], dp[mask] + task);
            }
        }
        return (dp.back() + sessionTime - 1) / sessionTime;
    }
};
