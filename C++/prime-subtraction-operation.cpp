// Time:  O(p + nlogp)
// Space: O(p)
// number theory, greedy, binary search

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        for (int i = 0; i < size(nums); ++i) {
            const auto& it = lower_bound(cbegin(PRIMES), cend(PRIMES), i - 1 >= 0 ? nums[i] - nums[i - 1] : nums[i]);
            if (it != cbegin(PRIMES)) {
                nums[i] -= *prev(it);
            }
            if (i - 1 >= 0 && nums[i - 1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }
};
