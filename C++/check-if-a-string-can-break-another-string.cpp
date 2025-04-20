// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        const auto& count1 = counter(s1), &count2 = counter(s2);
        return isBreak(count1, count2) || isBreak(count2, count1);
    }

private:
    bool isBreak(const vector<int>& count1, const const vector<int>& count2) {
        int curr1 = 0, curr2 = 0;
        for (int c = 0; c < 26; ++c) {
            curr1 += count1[c];
            curr2 += count2[c];
            if (curr1 < curr2) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> counter(const string& word) {
        vector<int> count(26);
        for (const auto& c : word) {
            ++count[c - 'a'];
        }
        return count;
    }
};
