// Time:  O(n * m * logr), r = max(nums)
// Space: O(n + logr)
// dp, mono deque, two pointers

class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        static const int INF = numeric_limits<int>::max();

        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const int L = bit_length(ranges::max(nums));
        const auto& update = [&](auto& cnt, int x, int d) {
            for (int i = 0; i < L; ++i) {
                if (x & (1 << i)) {
                    cnt[i] += d;
                }
            }
        };

        const auto& mask = [&](const auto& cnt, int l) {
            int result = 0;
            for (int i = 0; i < L; ++i) {
                if (cnt[i] == l) {
                    result |= 1 << i;
                }
            }
            return result;
        };

        vector<int> dp(size(nums) + 1, INF);
        dp[0] = 0;
        for (int j = 0; j < size(andValues); ++j) {
            vector<int> new_dp(size(dp), INF), cnt(L), l(size(dp));
            deque<int> dq;
            for (int right = j, left = right, idx = right; right < size(nums); ++right) {
                update(cnt, nums[right], +1);
                if (mask(cnt, right - left + 1) <= andValues[j]) {
                    for (; left <= right && mask(cnt, right - left + 1) <= andValues[j]; ++left) {
                        update(cnt, nums[left], -1);
                    }
                    --left;
                    update(cnt, nums[left], +1);  // try to move to the last left s.t. mask(cnt, right - left + 1) == andValues[j]
                }
                if ((andValues[j] & nums[right]) == andValues[j]) {
                    l[right + 1] = l[right] + 1;
                }
                if (mask(cnt, right - left + 1) != andValues[j]) {
                    continue;
                }
                // new_dp[right+1] = min(dp[left-l[left]], dp[left-l[left]+1], ..., dp[left])+nums[right]
                for (; idx <= left; ++idx) {
                    for (; !empty(dq) && dp[dq.back()] >= dp[idx]; dq.pop_back());
                    dq.emplace_back(idx);
                }
                for (; !empty(dq) && dq.front() < left - l[left]; dq.pop_front());
                if (!empty(dq)) {
                    if (dp[dq.front()] != INF) {
                        new_dp[right + 1] = dp[dq.front()] + nums[right];
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};
