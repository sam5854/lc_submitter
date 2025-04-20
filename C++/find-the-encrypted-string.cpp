// Time:  O(n)
// Space: O(1)
// string

class Solution {
public:
    string getEncryptedString(string s, int k) {
        rotate(begin(s), begin(s) + (k % size(s)), end(s));
        return s;
    }
};
