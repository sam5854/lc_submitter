// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        sort(begin(nums), end(nums));
        for (int i = size(nums) - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    result += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return result;
    }
};
