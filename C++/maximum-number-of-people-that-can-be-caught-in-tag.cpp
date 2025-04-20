// Time:  O(n)
// Space: O(1)
// greedy with two pointers solution

class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        int result = 0, i = 0, j = 0;
        while (i < size(team) && j < size(team)) {
            if (i + dist < j || team[i] != 1) {
                ++i;
            } else if (j + dist < i || team[j] != 0) {
                ++j;
            } else {
                ++result;
                ++i;
                ++j;
            }
        }
        return result;
    }
};
