// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    string baseNeg2(int N) {
        string result;
        while (N) {
            result += to_string(-N & 1);  // N % -2
            N = -(N >> 1);  // N /= -2
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};
