// Time:  O(n * sqrt(n))
// Space: O(n)

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), 
            [](const pair<int, int>& a, pair<int, int>& b) {
                return b.first == a.first ? a.second < b.second : b.first < a.first;
            });

        vector<vector<pair<int, int>>> blocks(1);
        for (const auto& p : people) {
            auto index = p.second;
            int i = 0;
            for (; i < blocks.size(); ++i) {
                if (index <= blocks[i].size()) {
                    break;
                }
                index -= blocks[i].size();
            }
            blocks[i].emplace(blocks[i].begin() + index, p);
            
            if (blocks[i].size() * blocks[i].size() > people.size()) {
                blocks.emplace(blocks.begin() + i + 1,
                               blocks[i].begin() + blocks[i].size() / 2,
                               blocks[i].end());
                blocks[i].erase(blocks[i].begin() + blocks[i].size() / 2, blocks[i].end());
            }
        }

        vector<pair<int, int>> result;
        for (const auto& block : blocks) {
            for (const auto& p : block) {
                result.emplace_back(p);
            }
        }
        return result;
    }
};
