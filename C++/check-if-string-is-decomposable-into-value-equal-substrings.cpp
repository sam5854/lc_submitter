// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isDecomposable(string s) {
        if (size(s) % 3 != 2) {
            return false;
        }
        int left;
        for (left = 0; left < size(s); left += 3) {
            if (std::adjacent_find(cbegin(s) + left, cbegin(s) + min(left + 3, int(size(s))),
                                   std::not_equal_to<>()) != cbegin(s) + min(left + 3, int(size(s)))) {
                break;
            }
        }
        int right;
        for (right = size(s) - 1; right >= left + 1  ; right -= 3) {
            if (std::adjacent_find(cbegin(s) + max(right - 2, left), cbegin(s) + right + 1,
                                   std::not_equal_to<>()) != cbegin(s) + right + 1) {
                break;
            }
        }
        return (right + 3) - left == 1;
    }
};
