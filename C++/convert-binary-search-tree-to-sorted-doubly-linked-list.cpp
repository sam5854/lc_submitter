// Time:  O(n)
// Space: O(h)
// Definition for a Node.

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node *left_head = root, *left_tail = root;
        Node *right_head = root, *right_tail = root;
        if (root->left) {
            left_head = treeToDoublyList(root->left);
            left_tail = left_head->left;
        }
        if (root->right) {
            right_head = treeToDoublyList(root->right);
            right_tail = right_head->left;
        }
        left_tail->right = root, right_head->left = root;
        root->left = left_tail, root->right = right_head;
        left_head->left = right_tail, right_tail->right = left_head;
        return left_head;
    }
};
