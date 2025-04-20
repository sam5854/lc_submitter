// Time:  O(m * n * sqrt(m + n))
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
    int maximumInvitations(vector<vector<int>>& grid) {
        BipGraph graph(size(grid), size(grid[0]));
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                graph.addEdge(i + 1, j + 1);
            }
        }
        return graph.hopcroftKarp();
    }
};
