// Time:  precompute: O(MAX_N)
//        runtime: O(n)
// Space: O(MAX_N)
// number theory

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (PRIMES_SET.count(nums[i][i])) {
                result = max(result, nums[i][i]);
            }
            if (PRIMES_SET.count(nums[i][size(nums) - 1 - i])) {
                result = max(result, nums[i][size(nums) - 1 - i ]);
            }
        }
        return result;
    }
};
