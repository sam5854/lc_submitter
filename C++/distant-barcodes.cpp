// Time:  O(n), k is the number of distinct barcode
// Space: O(k)

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        static const int k = 2;

        unordered_map<int, int> cnts;
        for (const auto& c : barcodes) {
            ++cnts[c];
        }
        const int bucket_cnt = max_element(cbegin(cnts), cend(cnts), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->second;
        vector<int> partial_sorted_cnts;
        for (const auto& [c, v] : cnts) {
            if (v == bucket_cnt) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        for (const auto& [c, v] : cnts) {
            if (v != bucket_cnt) {
                partial_sorted_cnts.emplace_back(c);
            }
        }
        vector<int> result(size(barcodes));
        int i = (size(barcodes) - 1) % k;
        for (const auto& c : partial_sorted_cnts) {
            for (int _ = 0; _ < cnts[c]; ++_) {
                result[i] = c;
                i += k;
                if (i >= size(result)) {
                    i = (i - 1) % k;
                }
            }
        }
        return result;
    }
};
