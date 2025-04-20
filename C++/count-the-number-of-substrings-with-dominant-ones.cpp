// Time:  O(n * sqrt(n)) = O(n^(3/2))
// Space: O(n)
// two pointers, sliding window

class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;
        vector<int> idxs = {-1};
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '0') {
                idxs.emplace_back(i);
            }
        }
        idxs.emplace_back(size(s));
        for (int i = 0, curr = 1; i < size(s); ++i) {
            if (idxs[curr] == i) {
                ++curr;
            }
            const int l = (-1 + sqrt(1 + 4 * (i + 1))) / 2;  // since c^2 <= (i+1)-c, thus c <= (-1+(1+4*(i+1))**0.5)/2
            for (int c = 0; c <= min(l, curr - 1); ++c) {
                if (c * c <= (i - idxs[(curr - c) - 1]) - c) {
                    result += min(min(idxs[curr - c], i) - idxs[(curr - c) - 1], ((i - idxs[(curr - c) - 1]) - c) - c * c + 1);
                }
            }
        }
        return result;
    }
};
