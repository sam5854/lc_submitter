// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr = 0, mx = 0, mn = 0;
        for (const auto& num : nums) {
            curr += num;
            mx = max(mx, curr);
            mn = min(mn, curr);
        }
        return mx - mn;
    }
};
