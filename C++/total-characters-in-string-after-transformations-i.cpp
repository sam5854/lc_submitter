// Time:  precompute: O(t + 26)
//        runtime:    O(n)
// Space: O(t + 26)
// precompute, dp

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int result = 0;
        for (const auto& x : s) {
            result = (result + DP[(x - 'a') + t]) % MOD;
        }
        return result;
    }
};
