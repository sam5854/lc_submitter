// Time:  O(n)
// Space: O(n)
// mono stack

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        vector<int> stk;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (empty(stk) || nums[stk.back()] > nums[i]) {
                stk.emplace_back(i);
            }
        }
        int result = 0;
        for (int left = 0; left < size(nums); ++left) {
            while (!empty(stk) && nums[stk.back()] < nums[left]) {
                result = max(result, stk.back() - left + 1); stk.pop_back();
            }
        }
        return result;
    }
};
