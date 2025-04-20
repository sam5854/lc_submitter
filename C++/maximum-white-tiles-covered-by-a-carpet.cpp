// Time:  O(nlogn)
// Space: O(1)
// sliding window, optimized from solution3

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        int result = 0;
        for (int left = 0, right = 0, gap = 0; left < size(tiles); ++left) {
            if (left - 1 >= 0) {
                gap -= tiles[left][0] - tiles[left - 1][1] - 1;
            }
            const int r = tiles[left][0] + carpetLen - 1;
            while (right + 1 < size(tiles) && r + 1 >= tiles[right + 1][0]) {
                ++right;
                gap += tiles[right][0] - tiles[right - 1][1] - 1;
            }
            result = max(result, min(tiles[right][1] - tiles[left][0] + 1, carpetLen) - gap);
        }
        return result;
    }
};
