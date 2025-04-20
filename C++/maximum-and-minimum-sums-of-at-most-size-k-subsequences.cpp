// Time:  O(nlogn)
// Space: O(n)
// sort, combinatorics, two pointers, sliding window
// reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types

class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int result = 0;
        for (int i = 0, cnt = 1; i < size(nums); ++i) {
            result = addmod(result, mulmod(addmod(nums[i], nums[size(nums) - 1 - i]), cnt));
            cnt = submod(mulmod(cnt, 2), nCr(i, k - 1));
        }
        return result;
    }
};
