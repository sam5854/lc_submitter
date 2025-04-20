// Time:  precompute: O(r)
//        runtime:    O(n)
// Space: O(r) 
// greedy, number theory

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (int i = size(nums) - 2; i >= 0; --i) {
            if (nums[i] <= nums[i + 1]) {
                continue;
            }
            if (SPF[nums[i]] > nums[i + 1]) {
                return -1;
            }
            nums[i] = SPF[nums[i]];
            ++result;
        }
        return result;
    }
};
