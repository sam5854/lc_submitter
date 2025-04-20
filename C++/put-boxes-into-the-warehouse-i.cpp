// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(rbegin(boxes), rend(boxes));
        int result = 0;
        for (const auto& h : boxes) {
            if (h > warehouse[result]) {
                continue;
            }
            if (++result == size(warehouse)) {
                break;
            }
        }
        return result;
    }
};
