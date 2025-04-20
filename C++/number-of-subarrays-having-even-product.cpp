// Time:  O(n)
// Space: O(1)
// dp, math

class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        int64_t result = (size(nums) + 1) * size(nums) / 2;
        int cnt = 0;
        for (const auto& x : nums) {
            cnt = (x % 2 == 1) ? cnt + 1 : 0;
            result -= cnt;
        }
        return result;
    }
};
