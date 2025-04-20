// Time:  O(nlogk)
// Space: O(n)
// heap

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        vector<bool> right(size(nums));
        priority_queue<int> max_heap1;
        for (int i = size(nums) - 1; i >= 0; --i) {
            if (size(max_heap1) == k && nums[i] > max_heap1.top()) {
                right[i] = true;
            } 
            max_heap1.emplace(nums[i]);
            if (size(max_heap1) == k + 1) {
                max_heap1.pop();
            }
        }
        int result = 0;
        priority_queue<int> max_heap2;
        for (int i = 0; i < size(nums); ++i) {
            if (size(max_heap2) == k && nums[i] > max_heap2.top() && right[i]) {
                ++result;
            } 
            max_heap2.emplace(nums[i]);
            if (size(max_heap2) == k + 1) {
                max_heap2.pop();
            }
        }
        return result;
    }
};
