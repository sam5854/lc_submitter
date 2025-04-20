// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        BIT bit(2 * m + 1);
        unordered_map<int, int> lookup;
        for (int i = 1; i <= m; ++i) {
            lookup[i] = m + i;
            bit.add(m + i, 1);
        }
        vector<int> result;
        int curr = m;
        for (const auto& q : queries) {
            auto i = lookup[q]; lookup.erase(q);
            result.emplace_back(bit.sum(i - 1));
            bit.add(i, -1);
            lookup[q] = curr;
            bit.add(curr--, 1);
        }
        return result;
    }
};
