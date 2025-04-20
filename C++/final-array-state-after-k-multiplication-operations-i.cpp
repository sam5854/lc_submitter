// Time:  O(n + (n + logr) + nlog(logr) + nlogn) = O(nlogn), assumed log(x) takes O(1) time
// Space: O(n)
// sort, two pointers, sliding window, fast exponentiation

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        static const double EPS = 1e-15;
        const auto& count = [](const auto& x, int target) {
            return static_cast<int>(target - x + EPS);
        };

        if (multiplier == 1) {
            return nums;
        }
        using P = pair<double, int>;
        vector<P> vals;
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(log(nums[i]) / log(multiplier), i);
        }
        sort(begin(vals), end(vals));
        int right = 1;
        for (int left = 0; right <= static_cast<int>(vals.back().first) + 1; ++right) {
            for (; left < size(vals) && count(vals[left].first, right) >= 1; ++left);
            if (k - left < 0) {
                --right;
                break;
            }
            k -= left;
        }
        if (right == static_cast<int>(vals.back().first) + 2) {
            --right;
        }
        for (int idx = 0; idx < size(vals); ++idx) {
            const auto& [x, i] = vals[idx];
            const int c = count(x, right);
            if (c <= 0) {
                break;
            }
            nums[i] *= pow(multiplier, c);
        }
        vals.clear();
        for (int i = 0; i < size(nums); ++i) {
            vals.emplace_back(nums[i], i);
        }
        sort(begin(vals), end(vals));
        const int q =  k / size(nums), r = k % size(nums);
        const int m = pow(multiplier, q);
        vector<int> result(size(nums));
        for (int idx = 0; idx < size(vals); ++idx) {
            const auto& [x, i] = vals[idx];
            result[i] = x * m * (idx < r ? multiplier : 1);
        }
        return result;
    }
};
