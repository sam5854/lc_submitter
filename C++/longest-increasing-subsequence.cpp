// Time:  O(nlogn)
// Space: O(n)
// Binary search solution with STL.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (const auto& num : nums) {
            insert(&LIS, num);
        }

        return LIS.size();
    }

private:
    void insert(vector<int> *LIS, const int target) {
        // Find the first index "left" which satisfies LIS[left] >= target
        auto it = lower_bound(LIS->begin(), LIS->end(), target);

        // If not found, append the target.
        if (it == LIS->end()) {
            LIS->emplace_back(target);
        } else {
            *it = target;
        }
    }
};
