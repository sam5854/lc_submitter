// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 0;
        for (int curr = n, base = 1; curr; base *= 10, curr /= 10) { 
            if (curr % 10 == 0 || (curr % 10 == 1 && curr != 1)) {
                a += base;
                curr -= 10;  // carry
            }
            a += base;
        }
        return {a, n - a};
    }
};
