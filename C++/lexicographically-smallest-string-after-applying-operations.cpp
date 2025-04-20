// Time:  O(100 * n^2) = O(n^2)
// Space: O(1)

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string result = s;
        vector<bool> even(10);
        while (!even[s[0] - '0']) {  // at most O(10) times
            even[s[0] - '0'] = true;
            vector<bool> odd(10);
            while (!odd[s[1] - '0']) {  // at most O(10) times
                odd[s[1] - '0'] = true;
                int best_rotate = 0;
                vector<bool> lookup(size(s));
                for (int i = b; !lookup[i]; i = (i + b) % size(s)) {  // find best rotation, at most O(n) times
                    lookup[i] = true;
                    if (less(s, i, best_rotate)) {  // O(n) time
                        best_rotate = i;
                    }
                }
                result = min(result, s.substr(best_rotate) + s.substr(0, best_rotate));                
                for (int k = 1; k < s.size(); k += 2) {  // flip odd index
                    s[k] = '0' + (s[k] - '0' + a) % 10;
                }
            }
            if (b % 2) {  // if rotate length is odd, even index could be also flipped
                for (int k = 0; k < size(s); k += 2) {  // flip even index
                    s[k] = '0' + (s[k] - '0' + a) % 10;
                }
            }
        }
        return result;
    }

private:
    bool less(const string &s, int i, int j) {
        for (int k = 0; k < size(s); ++k) {
            if (s[(k + i) % size(s)] != s[(k + j) % size(s)]) {
                return s[(k + i) % size(s)] < s[(k + j) % size(s)];
            }
        }
        return false;
    }
};
