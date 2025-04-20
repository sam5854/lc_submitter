// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (auto& num : nums) {
            if (num) {
                swap(nums[pos++], num);
            }
        }
    }
};
