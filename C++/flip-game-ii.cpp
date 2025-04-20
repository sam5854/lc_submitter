// Time:  O(n + c^2), c is max length of consecutive '+'
// Space: O(c)
// The best theory solution (DP, O(n + c^2)) could be seen here:
// https://leetcode.com/problems/flip-game-ii/discuss/73954/theory-matters-from-backtracking128ms-to-dp-0ms

class Solution {
public:
    bool canWin(string s) {
        replace(s.begin(), s.end(), '-', ' ');
        istringstream in(s);
        int g_final = 0;
        vector<int> g;  // Sprague-Grundy function of 0 ~ maxlen, O(n) space
        for (string t; in >> t; ) {  // Split the string
            int p = t.size();
            while (g.size() <= p) {  // O(c) time
                string x{t};
                int i = 0, j = g.size() - 2;
                while (i <= j) {  // The S-G value of all subgame states, O(c) time
                    // Theorem 2: g[game] = g[subgame1]^g[subgame2]^g[subgame3]...;
                    x[g[i++] ^ g[j--]] = '-';
                }
                // Find first missing number.
                g.emplace_back(x.find('+'));
            }
            g_final ^= g[p];
        }
        return g_final;  // Theorem 1: First player must win iff g(current_state) != 0
    }
};
