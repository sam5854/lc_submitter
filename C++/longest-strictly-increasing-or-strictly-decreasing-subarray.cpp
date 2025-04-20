// Time:  O(n)
// Space: O(1)
// array

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const auto& cmp = [](int x, int y) {
            return x < y ? -1 : (x > y ? 1 : 0);
        };

        int result = size(nums) == 1 || cmp(nums[0], nums[1]) == 0 ? 1 : 2;
        for (int i = 2, cnt = result; i < size(nums); ++i) {
            cnt = cmp(nums[i - 1], nums[i]) == 0 ? 1 : cmp(nums[i - 2], nums[i - 1]) == cmp(nums[i - 1], nums[i]) ? cnt + 1 : 2;
            result = max(result, cnt);
        }
        return result;
    }
};
