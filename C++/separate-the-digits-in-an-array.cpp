// Time:  O(n * logr)
// Space: O(1)
// array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int x = nums[i]; x; x /= 10) {
                result.emplace_back(x % 10);
            }
        }
        reverse(begin(result), end(result));
        return result;
    }
};
