// Time:  precompute: O(r * log(logr)), r = MAX_NUM
//        runtime:    O(n * log(logr))
// Space: O(r * log(logr))
// number theory, hash table

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int result = 2;
        unordered_map<int, int> lookup;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            for (const auto& p : PRIME_DIVISORS[nums[right]]) {
                left = max(left, lookup[p]);
                lookup[p] = right + 1;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
