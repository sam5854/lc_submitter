// Time:  O(n)
// Space: O(1)
// prefix sum, CodeChef Starters 146 - Bouncing Ball (https://www.codechef.com/problems/BOUNCE_BALL)

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int result = 0;
        for (int i = 0, curr = 0, total = accumulate(cbegin(nums), cend(nums), 0); i < size(nums); ++i) {
            if (nums[i] == 0) {
                result += max(2 - abs(curr - (total - curr)), 0);
            } else {
                curr += nums[i];
            }
        }
        return result;
    }
};
