// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = size(nums);
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        int result = 0, l = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (nums[i] <= nums[i - l] + n - 1) {
                ++l;
            }
        }
        return n - l;
    }
};
