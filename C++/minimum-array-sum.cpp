// Time:  O(nlogn)
// Space: O(n)
// greedy, case works
// Reference: https://leetcode.com/problems/minimum-array-sum/solutions/6078002/o-n-log-n-greedy/

class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        sort(begin(nums), end(nums));

        int left = 0;
        for (; left < size(nums); ++left) {
            if (nums[left] >= k) {
                break;
            }
        }
        int right = 0;
        for (; right < size(nums); ++right) {
            if (nums[right] >= 2 * k - 1) {
                break;
            }
        }

        int j = size(nums) - 1;
        for (; j >= right; --j) {
            if (!op1) {
                break;
            }
            --op1;
            nums[j] = (nums[j] + 1) / 2;
            if (op2) {
                --op2;
                nums[j] -= k;
            }
        }
    
        vector<bool> lookup(size(nums));
        int cnt = 0;
        int i = left;
        for (; i <= j; ++i) {
            if (!op2) {
                break;
            }
            --op2;
            if (k % 2 == 1 && nums[i] % 2 == 0) {
                lookup[i] = true;
            }
            nums[i] -= k;
        }

        for (; j >= i; --j) {
            if (!op1) {
                break;
            }
            --op1;
            if (k % 2 == 1 && nums[j] % 2 == 1) {
                ++cnt;
            }
            nums[j] = (nums[j] + 1) / 2;
        }

        vector<pair<int, int>> arr;
        for (int idx = 0; idx < i; ++idx) {
            arr.emplace_back(nums[idx], idx);
        }
        sort(begin(arr), end(arr));
        while (op1--) {
            const auto [x, idx] = arr.back(); arr.pop_back();
            nums[idx] = (x + 1) / 2;
            if (cnt && lookup[idx]) {
                --cnt;
                --nums[idx];
            }
        }
        return accumulate(cbegin(nums), cend(nums), 0);
    }
};
