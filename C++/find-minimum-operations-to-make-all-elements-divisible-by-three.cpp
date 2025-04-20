// Time:  O(n)
// Space: O(1)
// math

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for (const auto& x : nums) {
            if (x % 3 != 0) {
                ++result;
            }
        }
        return result;
    }
};
