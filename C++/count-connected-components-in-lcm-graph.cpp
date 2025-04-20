// Time:  O(n + tlogt), t = threshold
// Space: O(t)
// union find, number theory

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        UnionFind uf(threshold);
        vector<int> lookup(threshold, -1);
        int result = size(nums);
        for (const auto& x : nums) {
            if (x - 1 >= threshold) {
                continue;
            }
            for (int i = x; i <= threshold; i += x) {
                if (lookup[i - 1] == -1) {
                    lookup[i - 1] = x - 1;
                    continue;
                }
                if (uf.union_set(lookup[i - 1], x - 1)) {
                    --result;
                }
                if (i == x) {
                    break;
                }
            }
        }
        return result;
    }
};
