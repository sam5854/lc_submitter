// Time:  O(n * 5^(n/2))
// Space: O(n)

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        static const unordered_map<string, string> lookup{{"0", "0"}, {"1", "1"},
                                                          {"6", "9"}, {"8", "8"}, 
                                                          {"9", "6"}};
        vector<string> result = {""};
        if (n % 2) {
            result = {"0", "1", "8"};
        }
        for (int i = n % 2; i < n; i += 2) {
            vector<string> new_result;
            for (const auto& num : result) {
                for (const auto& [a, b] : lookup) {
                    if (i != n - 2 || a != "0") {
                        new_result.emplace_back(a + num + b);
                    }
                }
            }
            result = move(new_result);
        }
        return result;
    }
};
