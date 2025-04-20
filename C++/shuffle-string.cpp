// Time:  O(n)
// Space: O(1)
// in-place solution

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for (int i = 0; i < s.length(); ++i) {
            if (indices[i] == i) {
                continue;
            }
            auto move = s[i];
            for (int j = indices[i]; j != i; swap(indices[j], j)) {
                swap(s[j], move);
            }
            s[i] = move;
        }
        return s;
    }
};
