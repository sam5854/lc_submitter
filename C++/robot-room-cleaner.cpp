// Time:  O(n), n is the number of cells
// Space: O(n)

class Solution {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

    void cleanRoom(Robot& robot) {
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        dfs({0, 0}, robot, 0, &lookup);
    }
    
private:
    void dfs(const pair<int, int>& pos, Robot& robot, int dir,
             unordered_set<pair<int, int>, PairHash<int>> *lookup) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        robot.clean();
        for (int i = 0; i < directions.size(); ++i, dir = (dir + 1) % directions.size(), robot.turnRight()) {
            const auto& new_pos = pair(pos.first + directions[dir].first,
                                       pos.second + directions[dir].second);
            if (lookup->count(new_pos)) {
                continue;
            }
            lookup->emplace(new_pos);
            if (!robot.move()) {
                continue;
            }
            dfs(new_pos, robot, dir, lookup);
            goBack(robot);
        }
    }

    void goBack(Robot& robot) {
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};
