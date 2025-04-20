// Time:  O(n)
// Space: O(1)
// array, quick select

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        nth_element(begin(nums) + 1, (begin(nums) + 1) + (2 - 1), end(nums));
        return nums[0] + nums[1] + nums[2];
    }
};
