// Time:  O(l * nlogn)
// Space: O(n)
// sort, sliding window, prefix sum

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string> &words, int k) {
        vector<int> idxs(size(words));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& i, const auto& j) {
            return words[i] < words[j];
        });

        const auto& longest_common_prefix = [&](int k) {
            vector<int> lcp(size(words));
            for (int i = 0; i + (k - 1) < size(words); ++i) {
                const auto& left = words[idxs[i]];
                const auto& right = words[idxs[i + (k - 1)]];
                int j = 0;
                for (; j < min(size(left), size(right)); ++j) {
                    if(left[j] != right[j]) {
                        break;
                    }
                }
                lcp[i] = j;
            }
            return lcp;
        };

        vector<int> lcp = longest_common_prefix(k);
        vector<int> prefix(size(words));
        prefix[0] = lcp[0];
        for(int i = 0; i + 1 < size(prefix); ++i) {
            prefix[i + 1] = max(prefix[i], lcp[i + 1]);
        }
        vector<int> suffix(size(words));
        suffix[size(words) - 1] = lcp[size(words) - 1];
        for (int i = size(suffix) - 2; i >= 0; --i) {
            suffix[i] = max(suffix[i + 1], lcp[i]);
        }
        vector<int> result(size(words));
        const int mx = ranges::max(longest_common_prefix(k + 1));
        for (int i = 0; i < size(words); i++) {
            const int idx = idxs[i];
            const int mx1 = i - k >= 0 ? prefix[i - k] : 0;
            const int mx2 = i + 1 < size(words) ? suffix[i + 1] : 0;
            result[idx] = max({mx, mx1, mx2});
        }
        return result;
    }
};
