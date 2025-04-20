// Time:  O(n)
// Space: O(n)
// hash table

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int result = 0;
        unordered_set<int> lookup;
        for (const auto& x : nums) {
            result ^= x;
            if (lookup.count(x)) {
                continue;
            }
            lookup.emplace(x);
            result ^= x;
        }
        return result;
    }
};
