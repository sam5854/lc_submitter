// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> lookup;
        for (const auto& i : intervals) {
            ++lookup[i[0]];
            --lookup[i[1]];
        }
        int result = 0, curr = 0;
        for (const auto& [time, num] : lookup) {
            result = max(result, curr += num);
        }
        return result;
    }
};
