// Time:  O(n)
// Space: O(n)
// hash table

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> lookup(cbegin(nums), cend(nums));
        return accumulate(cbegin(nums), cend(nums), 0, [&](const auto& total, const auto&x) {
            return total + lookup.count(x - diff) * lookup.count(x - 2 * diff);
        });
    }
};
