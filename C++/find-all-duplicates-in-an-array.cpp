// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (const auto& i : nums) {
            if (nums[abs(i) - 1] < 0) {
                result.emplace_back(abs(i));
            } else {
                nums[abs(i) - 1] *= -1;
            }
        }
        return result;
    }
};
