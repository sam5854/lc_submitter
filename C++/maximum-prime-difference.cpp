// Time:  O(r + n), r = max(nums)
// Space: O(r)
// linear sieve of eratosthenes, number theory

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int left = -1, right = -1;
        for (int i = 0; i < size(nums); ++i) {
            if (SPF[nums[i]] != nums[i]) {
                continue;
            }
            if (left == -1) {
                left = i;
            }
            right = i;
        }
        return right - left;
    }
};
