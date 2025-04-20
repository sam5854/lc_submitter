// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(target); ++i) {
            lookup[target[i]] = i;
        }
        vector<int> lis;
        for (const auto& x : arr) {
            if (!lookup.count(x)) {
                continue;
            }
            auto it = lower_bound(begin(lis), end(lis), lookup[x]);
            if (it == end(lis)) {
                lis.emplace_back(lookup[x]);
            } else {
                *it = lookup[x];
            }
        }
        return size(target) - size(lis);
    }
};
