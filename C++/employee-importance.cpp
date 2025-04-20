// Time:  O(n)
// Space: O(h)
// Employee info

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        return dfs(employees, id);
    }

private:
    int dfs(const vector<Employee*>& employees, const int id) {
        if (!employees[id - 1]) {
            return 0;
        }
        auto result = employees[id - 1]->importance;
        for (const auto& id : employees[id - 1]->subordinates) {
            result += getImportance(employees, id);
        }
        return result;
    }
};
