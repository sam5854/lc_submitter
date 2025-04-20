// Time:  O(n)
// Space: O(h)
// Definition for a Node.

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        for (const auto& child : root->children) {
            depth = max(depth, maxDepth(child));
        }
        return 1 + depth;
    }
};
