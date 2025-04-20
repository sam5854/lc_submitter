// Time:  O(max(n * 2^n, 3^n))
// Space: O(2^n)

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const vector<int> candidates = findCandidates(nums, k);  // Time: O(n * 2^n)
        const int total = (1 << size(nums)) - 1;
        vector<int> dp(total + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int mask = 0; mask <= total; ++mask) {  // Time: O(3^n)
            if (__builtin_popcount(mask) % (size(nums) / k) != 0) {
                continue;
            }
            // submask enumeration:
            // => sum(nCr(n, k) * 2^k for k in xrange(n+1)) = (1 + 2)^n = 3^n
            // => Time: O(3^n), see https://cp-algorithms.com/algebra/all-submasks.html
            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                if (candidates[submask] == numeric_limits<int>::max() ||
                    dp[mask - submask] == numeric_limits<int>::max()) {
                    continue;
                }
                dp[mask] = min(dp[mask], dp[mask - submask] + candidates[submask]);
            }
        }
        return dp.back() != numeric_limits<int>::max() ? dp.back() : -1;
    }

private:                        
    vector<int> findCandidates(const vector<int>& nums, int k) {
        const int total = (1 << size(nums)) - 1;
        vector<int> result(total + 1, numeric_limits<int>::max());
        for (int mask = 0; mask <= total; ++mask) {
            if (__builtin_popcount(mask) != size(nums) / k) {
                continue;
            }
            int lookup = 0;
            int mx = 0, mn = numeric_limits<int>::max();
            bool duplicated = false;
            for (int i = 0; i < size(nums); ++i) {
                if ((mask & (1 << i)) == 0) {
                    continue;
                }
                if (lookup & (1 << nums[i])) {
                    duplicated = true;
                    break;
                }
                lookup |= (1 << nums[i]);
                mx = max(mx, nums[i]);
                mn = min(mn, nums[i]);
            }
            if (duplicated) {
                continue;
            }
            result[mask] = mx - mn;
        }
        return result;
    }
};
