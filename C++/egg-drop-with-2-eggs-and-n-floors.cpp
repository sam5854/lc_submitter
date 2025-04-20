// Time:  O(1)
// Space: O(1)
// see the proof: https://www.geeksforgeeks.org/puzzle-set-35-2-eggs-and-100-floors/

class Solution {
public:
    int twoEggDrop(int n) {
        return ceil((-1 + sqrt(1 + 8 * n)) / 2);    
    }
};
