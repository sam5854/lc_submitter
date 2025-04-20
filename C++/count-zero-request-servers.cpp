// Time:  O(nlogn + mlogm)
// Space: O(n + m)
// sort, two pointers

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(begin(logs), end(logs), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> events;
        for (int i = 0; i < size(queries); ++i) {
            events.emplace_back(queries[i], i);
        }
        sort(begin(events), end(events));

        vector<int> result(size(queries));
        vector<int> cnt(n);
        int curr = 0, left = 0, right = 0;
        for (const auto& [t, i] : events) {
            while (right < size(logs) && logs[right][1] <= t) {
                if (cnt[logs[right++][0] - 1]++ == 0) {
                    ++curr;
                }
            }
            while (left < right && logs[left][1] < t - x) {
                if (--cnt[logs[left++][0] - 1] == 0) {
                    --curr;
                }
            }
            result[i] = n - curr;
        }
        return result;
    }
};
