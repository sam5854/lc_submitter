// Time:  O(n * l + r), n = len(nums), l = len(nums[0])
// Space: O(r), r = max(nums)-min(nums)
// freq table, counting sort

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        static const int MAX_NUM = 1000;
        vector<int> cnt(MAX_NUM + 1);
        for (const auto& num : nums) {
            for (const auto& x : num) {
                ++cnt[x];
            }
        }
        vector<int> result;
        for (int i = 1; i <= MAX_NUM; ++i) {
            if (cnt[i] == size(nums)) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
