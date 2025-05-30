// Time:  O(nlogn)
// Space: O(1)
// sort, greedy, two pointers

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int left = 0;
        for (int right = (size(nums) + 1) / 2; right < size(nums); ++right) {
            if (nums[right] >= 2 * nums[left]) {
                ++left;
            }
        }
        return left * 2;
    }
};
