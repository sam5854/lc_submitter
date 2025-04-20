// Time:  O(n^2)
// Space: O(n)
// z-function

class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        // Template: https://cp-algorithms.com/string/z-function.html
        const auto& z_function = [](const auto& s, int left, int right) {  // Time: O(n), Space: O(n)
            vector<int> z(right - left + 1);
            for (int i = 1, l = 0, r = 0; i < size(z); ++i) {
                if (i <= r) {
                    z[i] = min(r - i + 1, z[i - l]);
                }
                while (i + z[i] < size(z) && s[left + z[i]] == s[left + i + z[i]]) {
                    ++z[i];
                }
                if (i + z[i] - 1 > r) {
                    l = i, r = i + z[i] - 1;
                }
            }
            return z;
        };

        int result = 0;
        const auto& z0 = z_function(nums, 0, size(nums) - 1);
        for (int i = 1; i + 1 < size(nums); ++i) {
            const auto& zi = z_function(nums, i, size(nums) - 1);
            for (int j = i + 1; j < size(nums); ++j) {
                if ((z0[i] >= i && (j - i >= i)) || zi[j - i] >= j - i) {
                    ++result;
                }
            }
        }
        return result;
    }
};
