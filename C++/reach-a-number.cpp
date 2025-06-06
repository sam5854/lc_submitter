// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        auto k = static_cast<int>(ceil((-1 + sqrt(1 + 8.0 * target)) / 2));
        target -= k * (k + 1) / 2;
        return (target % 2 == 0) ? k : k + 1 + k % 2;
    }
};
