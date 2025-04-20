// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0, left = 0, right = 0;
        for (; right < nums.size(); ++right) {
            count += (nums[right] == 0);
            if (count >= 2) {
                count -= (nums[left++] == 0);
            }
        }
        return (right - left) - 1;
    }
};
