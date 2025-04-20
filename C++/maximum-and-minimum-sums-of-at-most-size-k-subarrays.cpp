// Time:  O(n)
// Space: O(k)
// two pointers, sliding window, mono deque

class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        const auto& count = [&](const auto& check) {
            int64_t result = 0, total = 0;
            deque<int> dq;
            for (int right = 0; right < size(nums); ++right) {
                while (!empty(dq) && !check(nums[dq.back()], nums[right])) {
                    const int i  = dq.back(); dq.pop_back();
                    const int64_t cnt = i - (!empty(dq) ? dq.back() + 1 : max(right - k + 1, 0)) + 1;
                    total -= cnt * nums[i];
                }
                const int64_t cnt = right - (!empty(dq) ? dq.back() + 1 : max(right - k + 1, 0)) + 1;
                dq.emplace_back(right);
                total += cnt * nums[right];
                result += total;
                if (right >= k - 1) {
                    total -= nums[dq[0]];
                    if (dq[0] == right - (k - 1)) {
                        dq.pop_front();
                    }
                }
            }
            return result;
        };
    
        return count([](const auto& a, const auto& b) { return a < b; }) + 
               count([](const auto& a, const auto& b) { return a > b; });
    }
};
