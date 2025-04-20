// Time:  O(nlogn + mlogm + nlogk + mlogk), k is max(max(nums), max(xi))
// Space: O(nlogk)

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(begin(nums), end(nums));
        int max_val = max(nums.back(),
                          (*max_element(cbegin(queries), cend(queries),
                                        [](const auto& a, const auto& b) {
                                            return a[0] < b[0];
                                        }))[0]);
        for (int i = 0; i < size(queries); ++i) {
            queries[i].insert(begin(queries[i]), i);
        }
        sort(begin(queries), end(queries),
             [](const auto& a, const auto& b) {
                 return a[2] < b[2];
             });
        vector<int> result(size(queries));
        Trie trie(bit_length(max_val));
        int j = 0;
        for (const auto& q : queries) {
            int i = q[0], x = q[1], m = q[2];
            for (; j < size(nums) && nums[j] <= m; ++j) {
                trie.insert(nums[j]);
            }
            result[i] = trie.query(x);
        }
        return result;
    }

private:
    int bit_length(int x) {
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};
