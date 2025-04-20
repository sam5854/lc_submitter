// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int mirrorReflection(int p, int q) {
        // explanation commented in the following solution
        return (p & -p) > (q & -q) ? 2 : (p & -p) < (q & -q) ? 0 : 1;
    }
};
