// Time:  O(n)
// Space: O(1)
// two pointers

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int64_t result = 0;
        int mn = numeric_limits<int>::max();
        int mx = numeric_limits<int>::min();
        for (int right = 0, left = 0; right < size(nums); ++right) {
            if (mn <= nums[right] && nums[right] <= mx) {
                mn = max(mn, nums[right] - 2);
                mx = min(mx, nums[right] + 2);
            } else {
                mn = nums[right] - 2;
                mx = nums[right] + 2;
                for (left = right - 1; left >= 0; --left) {
                    if (!(mn <= nums[left] && nums[left] <= mx)) {
                        break;
                    }
                    mn = max(mn, nums[left] - 2);
                    mx = min(mx, nums[left] + 2);
                }
                ++left;
            }
            result += right - left + 1;
        }
        return result;
    }
};
