// Time:  O(s + logn), s is the number of elements in the array
// Space: O(1)

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int result = 0, reachable = 0;
        for (const auto& x : nums) {
            if (x > n) {
                break;
            }
            while (!(reachable >= x - 1)) {
                ++result;
                reachable += reachable + 1;
            }
            if (reachable >= n - x) {
                return result;
            }
            reachable += x;
        }
        ++result;
        for (; !(reachable >= n - (reachable + 1)); reachable += reachable + 1) {
            ++result;
        }
        return result;
    }
};
