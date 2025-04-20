// Time:  O(n)
// Space: O(n)
// codeforce, https://codeforces.com/contest/1782/problem/B
// freq table

class Solution {
public:
    int countWays(vector<int>& nums) {
        vector<int> cnt(size(nums) + 1);
        for (const auto& x : nums) {
            ++cnt[x];
        }
        int result = 0;
        for (int i = 0, prefix = 0; i <= size(nums); ++i) {
            if (prefix == i && cnt[i] == 0) {
                ++result;
            }
            prefix += cnt[i];
        }
        return result;
    }
};
