// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    string arrangeWords(string text) {
        text.front() = tolower(text.front());
        stringstream ss(text);
        string word;
        map<int, string> lookup;
        while (ss >> word) {
            lookup[word.size()] += word + " ";
        }
        string result;
        for (const auto& [_, word]: lookup) {
            result += word;
        }
        result.pop_back();
        result.front() = toupper(result.front());
        return result;
    }
};
