// Time:  O(n)
// Space: O(n)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double delta = numeric_limits<double>::max();
        while (delta > 1e-5) {
            delta = getDelta(left, nums, k);
            left += delta;
        }
        return left;
    }

private:
    double getDelta(double avg, const vector<int>& nums, int k) {
        vector<double> accu(nums.size() + 1);
        int minval_pos = -1;
        double delta = 0.0;
        for (int i = 0; i < nums.size(); ++i) {
            accu[i + 1] = nums[i] + accu[i] - avg;
            if (i >= k - 1) {
                if (minval_pos == -1 || accu[i - k + 1] < accu[minval_pos]) {
                    minval_pos = i - k + 1;
                }
                if (accu[i+1] - accu[minval_pos] >= 0) {
                    delta = max(delta, (accu[i + 1] - accu[minval_pos]) / (i + 1 - minval_pos));
                }
            }
        }
        return delta;
    }
};
