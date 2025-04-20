// Time:  O(n)
// Space: O(n)
// hash table

class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        return (*max_element(cbegin(nums), cend(nums)) -
                *min_element(cbegin(nums), cend(nums)) + 1) == size(nums) &&
               size(nums) == size(unordered_set<int>(cbegin(nums), cend(nums)));
    }
};
