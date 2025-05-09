// Time:  O(mlogm + n + mlogn)
// Space: O(n)
// one heap solution

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        vector<pair<int64_t, int>> rooms(n, {meetings[0][0], -1});
        int i = 0;
        for (auto& room : rooms) {
            room.second = i++;
        }
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap(cbegin(rooms), cend(rooms));
        vector<int> result(n);
        for (const auto& m : meetings) {
            const int s = m[0], e = m[1];
            while (!empty(min_heap) && min_heap.top().first < s) {
                const auto [_, i] = min_heap.top(); min_heap.pop();
                min_heap.emplace(s, i);
            }
            const auto [e2, i] = min_heap.top(); min_heap.pop();
            min_heap.emplace(e2 + (e - s), i);
            ++result[i];
        }
        return distance(cbegin(result), max_element(cbegin(result), cend(result)));
    }
};
