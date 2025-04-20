// Time:  O(h)
// Space: O(1)
// Definition for a Node.

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        auto a = p, b = q;
        while (a != b) {
            a = a ? a->parent : q;
            b = b ? b->parent : p;
        }
        return a;
    }
};
