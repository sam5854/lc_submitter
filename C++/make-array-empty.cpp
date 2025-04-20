// Time:  O(nlogn)
// Space: O(n)
// sort

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return nums[a] < nums[b];
        });
        int64_t result = size(idxs);
        for (int i = 0; i + 1 < size(idxs); ++i) {
            if (idxs[i] > idxs[i + 1]) {
                result += size(idxs) - (i + 1);
            }
        }
        return result;
    }
};
