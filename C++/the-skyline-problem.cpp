// Time:  O(nlogn)
// Space: O(n)
// BST solution.

class Solution {
public:
    enum {start, end, height};
    
    struct Endpoint {
        int height;
        bool isStart;
    };
    
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        map<int, vector<Endpoint>> point_to_height;  // Ordered, no duplicates.
        for (const auto& building : buildings) {
            point_to_height[building[start]].emplace_back(Endpoint{building[height], true});
            point_to_height[building[end]].emplace_back(Endpoint{building[height], false});
        }

        vector<pair<int, int>> res;
        map<int, int> height_to_count;  // BST.
        int curr_max = 0;
        // Enumerate each point in increasing order.
        for (const auto& kvp : point_to_height) {
            const auto& point = kvp.first;
            const auto& heights = kvp.second;

            for (const auto& h : heights) {
                if (h.isStart) {
                    ++height_to_count[h.height];
                } else {
                    --height_to_count[h.height];
                    if (height_to_count[h.height] == 0) {
                        height_to_count.erase(h.height);
                    }
                }
            }

            if (height_to_count.empty() ||
                curr_max != height_to_count.crbegin()->first) {
                curr_max = height_to_count.empty() ?
                           0 : height_to_count.crbegin()->first;
                res.emplace_back(point, curr_max);
            }
        }
        return res;
    }
};
