// Time:  O(max_t * m * n), max_t is max_target
// Space: O(max_t)
// optimized from solution2 (using bitset), runtime: 32 ms

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        static const int MAX_TARGET = 800;

        int chosen_min = 0;
        for (const auto& row : mat) {
            chosen_min += *min_element(cbegin(row), cend(row));
        }
        if (chosen_min >= target) {
            return chosen_min - target;
        }
        bitset<(2 * MAX_TARGET - 2) + 1> bs(1); // total < 2*target - 1
        for (const auto& row : mat) {
            bitset<(2 * MAX_TARGET - 2) + 1> new_bs;
            for (const auto& x : row) {
                new_bs |= bs << x;
            }
            bs = move(new_bs);
        }
        int result = size(bs);
        for (int total = chosen_min; total < size(bs); ++total) {
            if (!bs[total]) {
                continue;
            }
            result = min(result, abs(target - total));
            if (total > target) {
                break;
            }
        }
        return result;
    }
};
