// Time:  O(n)
// Space: O(n)
// dp, mono deque

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        vector<int> dp(size(prices) + 1, numeric_limits<int>::max());
        dp[0] = 0;
        deque<int> dq;
        for (int i = 0, j = 0; i < size(prices); ++i) {
            while (!empty(dq) && dp[dq.back()] + prices[dq.back()] >= dp[i] + prices[i]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
            for (; j + (j + 1) < i; ++j) {
                assert(!empty(dq));
                if (dq.front() == j) {
                    dq.pop_front();
                }
            }
            dp[i + 1] = dp[dq.front()] + prices[dq.front()];
        }
        return dp.back();
    }
};
