// Time:  O(nlogn + mlogn)
// Space: O(n)
// line sweep, binary search

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> cnt;
        for (const auto& flower : flowers) {
            ++cnt[flower[0]];
            --cnt[flower[1] + 1];
        }
        vector<int> prefix = {0};
        vector<int> events;
        for (const auto& [k, v] : cnt) {
            events.emplace_back(k);
            prefix.emplace_back(prefix.back() + v);
        }
        vector<int> result;
        for (const auto& t : persons) {
            int i = distance(cbegin(events), upper_bound(cbegin(events), cend(events), t));
            result.emplace_back(prefix[i]);
        }
        return result;
    }
};
