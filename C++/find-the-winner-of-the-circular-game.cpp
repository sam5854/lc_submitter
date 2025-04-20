// Time:  O(n)
// Space: O(1)
// bottom-up solution

class Solution {
public:
    int findTheWinner(int n, int k) {
        int idx = 0;
        for (int i = 1; i < n; ++i) {
            idx = (idx + k) % (i + 1);
        }
        return idx + 1;
    }
};
