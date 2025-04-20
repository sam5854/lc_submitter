// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool findGameWinner(int n) {
        // a pattern appears every 6 grundy numbers in binary forms:
        // 0000,       (0000)01,       (0000)11,                 ((0000)^(0000+1))10,       (0000)11,       (0000)11
        // 0000,     (0000+1)01,     (0000+1)11,           ((0000+1)^((0000+1)+1))10,     (0000+1)11,     (0000+1)11
        // 0000, ((0000+1)+1)01, ((0000+1)+1)11,   (((0000+1)+1)^(((0000+1)+1)+1))10, ((0000+1)+1)11, ((0000+1)+1)11
        // ...
        // 0000,       (XXXX)01,       (XXXX)11,                 ((XXXX)^(XXXX+1))10,       (XXXX)11,       (XXXX)11
        // 0000,     (XXXX+1)01,     (XXXX+1)11,           ((XXXX+1)^((XXXX+1)+1))10,     (XXXX+1)11,     (XXXX+1)11
        // => grundy[6k+1] = 0
        //    grundy[6k+2] = 4k+1
        //    grundy[6k+3] = 4k+3
        //    grundy[6k+4] = 4(k^(k+1))+2
        //    grundy[6k+5] = 4k+3
        //    grundy[6k+6] = 4k+3
        return n % 6 != 1;
    }
};
