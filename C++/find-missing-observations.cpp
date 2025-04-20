// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        static const int MAX_V = 6;
        static const int MIN_V = 1;
        
        const int total = accumulate(cbegin(rolls), cend(rolls), 0);
        const int missing = mean * (n + size(rolls)) - total;
        if (missing < MIN_V * n || missing > MAX_V * n) {
            return {};
        }
        const int q = missing / n;
        const int r = missing % n;
        vector<int> result(n);
        for (int i = 0; i < size(result); ++i) {
            result[i] = q + int(i < r);
        }
        return result;
    }
};
