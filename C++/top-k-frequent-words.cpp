// Time:  O(n + klogk) on average
// Space: O(n)
// Quick Select Solution

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (const auto& word : words) {
            ++counts[word];
        }
        vector<pair<int, string>> p;
        for (const auto& kvp : counts) {
            p.emplace_back(-kvp.second, kvp.first);
        }
        nth_element(p.begin(), p.begin() + k - 1, p.end());  // O(n) time on average.
        sort(p.begin(), p.begin() + k);  // O(klogk) time.
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(p[i].second);
        }
        return result;
    }
};
