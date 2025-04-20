// Time:  O(n)
// Space: O(n)

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<int> possible(size(wordlist));
        iota(begin(possible), end(possible), 0);
        int n = 0;
        while (n < 6) {
            auto guess = find_guess_with_most_frequent_chars(wordlist, possible);
            n = master.guess(wordlist[guess]);
            vector<int> new_possible;
            for (const auto& j : possible) {
                if (match(wordlist[guess], wordlist[j]) == n) {
                    new_possible.emplace_back(j);
                }
            }
            possible = move(new_possible);
        }
    }

private:
    int find_guess_with_most_frequent_chars(
        const vector<string>& wordlist,
        const vector<int>& possible) {
        vector<vector<int>> count(6, vector<int>(26));
        for (int i = 0; i < 6; ++i) {
            for (const auto& p : possible) {
                ++count[i][wordlist[p][i] - 'a'];
            }
        }
        int guess = 0, max_score = 0;
        for (const auto& p : possible) {
            int score = 0;
            for (int i = 0; i < 6; ++i) {
                score += count[i][wordlist[p][i] - 'a'];
            }
            if (score > max_score) {
                max_score = score;
                guess = p;
            }
        }
        return guess;
    }

    int match(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < size(a); ++i) {
            if (a[i] == b[i]) {
                ++matches;
            }
        }
        return matches;
    }
};
