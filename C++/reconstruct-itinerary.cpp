// Time:  O(|V| + |E|log|V|)
// Space: O(|V| + |E|)
// Hierholzer Algorithm

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        static const string origin{"JFK"};

        unordered_map<string, vector<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].emplace_back(ticket[1]);
        }
        for (auto& [k, v] : adj) {
            sort(rbegin(v), rend(v));
        }
        
        vector<string> result;
        vector<string> stk = {origin};
        while (!empty(stk)) {
            while (!empty(adj[stk.back()])) { 
                auto x = adj[stk.back()].back();
                adj[stk.back()].pop_back();
                stk.emplace_back(x);
                
            }
            result.emplace_back(stk.back());
            stk.pop_back();
        }
        reverse(begin(result), end(result));
        return result;
    }
};
