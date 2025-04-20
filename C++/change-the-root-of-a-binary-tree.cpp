// Time:  O(h)
// Space: O(1)
// Definition for a Node.

class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        Node *curr = leaf, *parent = nullptr;
        while (true) {
            auto child = curr->parent;
            curr->parent = parent;
            if (curr->left == parent) {
                curr->left = nullptr;
            } else {
                curr->right = nullptr;
            }
            if (curr == root) {
                break;
            }
            if (curr->left) {
                curr->right = curr->left;
            }
            curr->left = child;
            parent = curr, curr = child;
        }
        return leaf;
    }
};
