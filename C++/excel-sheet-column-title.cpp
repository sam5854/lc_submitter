// Time:  O(logn)
// Space: O(1)
// Iterative solution.

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        int dvd{n};
        
        while (dvd) {
            result.push_back((dvd - 1) % 26 + 'A');
            dvd = (dvd - 1) / 26;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
