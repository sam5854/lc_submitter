// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<int> lookup(2 * size(nums) + 1);
        lookup[0 + size(nums)] = 1;
        int result = 0, total = 0, same = 0, more = 0;
        for (const auto& num : nums) {
            total += (num == 1) ? 1 : -1;
            const int new_same = lookup[total + size(nums)];
            const int new_more = (num == 1) ? (same + more + 1) % MOD : (more - new_same + MOD) % MOD;
            ++lookup[total + size(nums)];
            result = (result + new_more) % MOD;
            same = new_same, more = new_more;
        }
        return result;
    }
};
