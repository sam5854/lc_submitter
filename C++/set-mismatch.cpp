// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x_xor_y = 0;
        for (int i = 0; i < nums.size(); ++i) {
            x_xor_y ^= nums[i] ^ (i + 1);
        }
        int bit = x_xor_y & ~(x_xor_y - 1);
        vector<int> result(2);
        for (int i = 0; i < nums.size(); ++i) {
            result[static_cast<bool>(nums[i] & bit)] ^= nums[i];
            result[static_cast<bool>((i + 1) & bit)] ^= i + 1;
        }
        if (find(nums.begin(), nums.end(), result[0]) == nums.end()) {
            swap(result[0], result[1]);
        }
        return result;
    }
};
