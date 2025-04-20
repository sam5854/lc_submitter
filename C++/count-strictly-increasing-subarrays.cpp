// Time:  O(n)
// Space: O(1)
// two pointers

class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int64_t result = 1, l = 1;
        for (int i = 1; i < size(nums); ++i) {
            if (nums[i - 1] >= nums[i]) {
                l = 0;
            }
            result += ++l;
        }
        return result;
    }
};
