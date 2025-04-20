// Time:  O(n)
// Space: O(n)
// greedy, sort

class Solution {
public:
    int sortArray(vector<int>& nums) {
        const auto& min_moves = [&](int d) {
            const auto& index = [&](int x) {
                return (x == 0) ? d * (size(nums) - 1) : x - d;
            };
            vector<bool> lookup(size(nums));
            int result = size(nums);
            for (int i = 0; i < size(nums); ++i) {
                if (lookup[nums[i]]) {
                    continue;
                }
                int l = 0;
                for (; !lookup[nums[i]]; ++l, i = index(nums[i])) {
                    lookup[nums[i]] = true;
                }
                --result;
                if (l >= 2) {
                    result += 2;
                }
            }
            return result - 2 * static_cast<int>(nums[d * (size(nums) - 1)] != 0);
        };

        return min(min_moves(0), min_moves(1));
    }
};
