// Time:  O(n)
// Space: O(k), k = value
// freq table

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> cnt;
        for (const auto& x: nums) {
            ++cnt[(x % value + value) % value];
        }
        int mn = 0;
        for (int i = 0; i < value; ++i) {
            if (cnt[i] < cnt[mn]) {
                mn = i;
            }
        }
        return value * cnt[mn] + mn;
    }
};
