// Time:  O(m * n * sqrt(m * n))
// Space: O(m * n)
// template from https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-2-implementation/
// A class to represent Bipartite graph for Hopcroft
// Karp implementation
// Time:  O(E * sqrt(V))
// Space: O(V)
// Returns size of maximum matching
// Returns true if there is an augmenting path, else returns
// false
// Returns true if there is an augmenting path beginning with free vertex u
// Constructor
// To add edge from u to v and v to u
// Hopcroft-Karp bipartite matching

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        static vector<pair<int, int>> directions = {{-1, -1}, {0, -1}, {1, -1},
                                                    {-1, 1}, {0, 1}, {1, 1}};
        unordered_map<int, int> lookup;
        int u = 0, v = 0;
        for (int i = 0; i < seats.size(); ++i) {
            for (int j = 0; j < seats[0].size(); ++j) {
                if (seats[i][j] != '.') {
                    continue;
                }
                lookup[i * seats[0].size() + j] = (j % 2 == 0) ? ++u : ++v;
            }
        }
        BipGraph g(seats.size() * seats[0].size(), seats.size() * seats[0].size());
        for (int i = 0; i < seats.size(); ++i) {
            for (int j = 0; j < seats[0].size(); j += 2) {
                if (seats[i][j] != '.') {
                    continue;
                }
                for (const auto& [dx, dy] : directions) {
                    const auto& [ni, nj] = make_pair(i + dx, j + dy);
                    if (0 <= ni && ni < seats.size() &&
                        0 <= nj && nj < seats[0].size() &&
                        seats[ni][nj] == '.') {
                        g.addEdge(lookup[i * seats[0].size() + j],
                                  lookup[ni * seats[0].size() + nj]);
                    }
                }
            }
        }
        return u + v - g.hopcroftKarp();
    }
};
