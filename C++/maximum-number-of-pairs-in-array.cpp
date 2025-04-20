// Time:  O(n + r)
// Space: O(r), r = max(nums)
// freq table

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> cnt(*max_element(cbegin(nums), cend(nums)) + 1);
        int pair_cnt = 0;
        for (const auto& x : nums) {
            cnt[x] ^= 1;
            if (!cnt[x]) {
                ++pair_cnt;
            }
        }
        return {pair_cnt, static_cast<int>(size(nums)) - 2 * pair_cnt};
    }
};
