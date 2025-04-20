// Time:  O(s * t)
// Space: O(s)

class Solution {
public:
    string minWindow(string S, string T) {
        vector<vector<int>> lookup(S.size() + 1, vector<int>(26, -1));
        vector<int> find_char_next_pos(26, -1);
        for (int i = S.length() - 1; i >= 0; --i) {
            find_char_next_pos[S[i] - 'a'] = i + 1;
            lookup[i] = find_char_next_pos;
        }
        
        int min_i = -1, min_len = numeric_limits<int>::max();
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] != T[0]) {
                continue;
            }
            int start = i;
            for (const auto& c : T) {
                start = lookup[start][c - 'a'];
                if (start == -1) {
                    break;
                }
            }
            if (start != -1) {
               if (start - i < min_len) {
                   min_i = i;
                   min_len = start - i;
               }
            }
        }
        return min_i != -1 ? S.substr(min_i, min_len) : "";
    }
};
