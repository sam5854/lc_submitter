// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3));
        int finish = stoi(finishTime.substr(0, 2)) * 60 + stoi(finishTime.substr(3));
        if (start > finish) {
            finish += 1440;
        }
        return max(finish / 15 - (start + 15 - 1) / 15, 0);
    }
};
