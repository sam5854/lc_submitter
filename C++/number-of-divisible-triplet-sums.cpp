// Time:  O(n^2)
// Space: O(n)
// freq table

class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        int result = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                if (cnt.count((nums[i] + nums[j]) % d)) {
                    result += cnt[(nums[i] + nums[j]) % d];
                }
            }
            ++cnt[((-nums[i]) % d + d) % d];
        }
        return result;
    }
};
