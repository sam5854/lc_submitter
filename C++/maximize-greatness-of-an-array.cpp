// Time:  O(n)
// Space: O(n)
// freq table, contructive algorithms

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        return size(nums) - max_element(cbegin(cnt), cend(cnt), [](const auto& x, const auto& y) {
            return x.second < y.second;
        })->second;
    }
};
