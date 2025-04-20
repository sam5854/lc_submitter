// Time:  O(x)
// Space: O(x)
// memoization

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        unordered_map<int, int> lookup;
        const function<int (int)> memoization = [&](int x) {
            if (y >= x) {
                return y - x;
            }
            if (!lookup.count(x)) {
                lookup[x] = x - y;
                for (const auto& d : {5, 11}) {
                    lookup[x] = min(lookup[x], min(x % d, d - x % d) + memoization(x / d + (d - x % d < x % d ? 1 : 0)) + 1);
                }
            }
            return lookup[x];
        };

        return memoization(x);
    }
};
