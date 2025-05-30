// Time:  O(n)
// Space: O(1)
// one pass, array

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mx = numeric_limits<int>::min(), mn = numeric_limits<int>::max();
        int result = -1;
        for (const auto& x : nums) {
            if (mn < x && x < mx) {
                return x;
            }
            if (x < mn) {
                result = mn;
                mn = x;
            }
            if (x > mx) {
                result = mx;
                mx = x;
            }
        }
        return mn < result && result < mx ? result : -1;
    }
};
