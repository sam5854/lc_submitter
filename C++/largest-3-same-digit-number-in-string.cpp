// Time:  O(n)
// Space: O(1)
// string

class Solution {
public:
    string largestGoodInteger(string num) {
        char result = 0;
        for (int i = 0, cnt = 0; i < size(num); ++i) {
            ++cnt;
            if (i + 1 < size(num) && num[i] == num[i + 1]) {
                continue;
            }
            if (cnt >= 3) {
                result = max(result, num[i]);
            }
            cnt = 0;
        }
        return result ? string(3, result) : "";
    }
};
