// Time:  O(n^2)
// Space: O(n^2)
// freq table

class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int64_t result = 0;
        unordered_map<double, int> cnt;
        for (int r = 4; r + 2 < size(nums); ++r) {
            const int q = r - 2;
            for (int p = 0; p <= q - 2; ++p) {
                ++cnt[static_cast<double>(nums[p]) / nums[q]];
            }
            for (int s = r + 2; s < size(nums); ++s) {
                result += cnt[static_cast<double>(nums[s]) / nums[r]];
            }
        }
        return result;
    }
};
