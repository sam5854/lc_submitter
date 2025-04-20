// Time:  O(m * n)
// Space: O(l), l is min(len(arr) for arr in arrays)

class Solution {
public:
    vector<int> longestCommomSubsequence(vector<vector<int>>& arrays) {
        const auto min_cit = min_element(cbegin(arrays), cend(arrays),
                                         [](const auto& a, const auto& b) {
                                             return size(a) < size(b);
                                         });
        vector<int> result = *min_cit;
        for (auto cit = cbegin(arrays); cit != cend(arrays); ++cit) {
            if (cit == min_cit) {
                continue;
            }
            vector<int> new_result;
            for (int i = 0, j = 0; i != size(result) && j != size(*cit);) {
                if (result[i] < (*cit)[j]) {
                    ++i;
                } else if (result[i] > (*cit)[j]) {
                    ++j;
                } else {
                    new_result.emplace_back(result[i]);
                    ++i;
                    ++j;
                }
            }
            result = move(new_result);
        }
        return result;
    }
};
