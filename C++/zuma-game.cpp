// Time:  O((b+h)^2 * h!*(b+h-1)!/(b-1)!)
// Space: O((b+h) * h!*(b+h-1)!/(b-1)!)
// brute force solution with worse complexity but pass

class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<string, unordered_map<string, int>> lookup;
        int result = findMinStepHelper(board, hand, &lookup);
        return result > hand.size() ? -1 : result;
    }

private:
    int findMinStepHelper(const string& board, const string& hand,
                          unordered_map<string, unordered_map<string, int>> *lookup) {
        if (board.empty()) {
            return 0;
        }
        if (hand.empty()) {
            return MAX_STEP;
        }
        if ((*lookup)[board][hand]) {
            return (*lookup)[board][hand];
        }

        int result = MAX_STEP;
        for (int i = 0; i < hand.size(); ++i) {
            for (int j = 0; j <= board.size(); ++j) {
                const auto& next_board = shrink(board.substr(0, j) + hand.substr(i, 1) + board.substr(j));
                const auto& next_hand = hand.substr(0, i) + hand.substr(i + 1);
                result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1);
            }
        }
        return (*lookup)[board][hand] = result;
    }
    
    string shrink(string s) {  // Time: O(n^2), Space: O(1)
        bool changed = true;
        while (changed) {
            changed = false;
            for (int start = 0, i = 0; start < size(s); ++start) {
                while(i < size(s) && s[start] == s[i]) {
                    ++i;
                }
                if (i - start >= 3) {
                    s = s.substr(0, start) + s.substr(i); 
                    changed = true;
                    break;
                } 
            }
        }
        return s;
    }

    static const int MAX_STEP = 6;
};
