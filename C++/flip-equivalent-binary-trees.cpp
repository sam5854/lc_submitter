// Time:  O(n)
// Space: O(h)
// bfs solution

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode *> q1({root1}), q2({root2});
        while (!q1.empty() && !q2.empty()) {
            auto node1 = q1.front(); q1.pop();
            auto node2 = q2.front(); q2.pop();
            if (!node1 && !node2) {
                continue;
            }
            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }
            if ((!node1->left && !node2->right) ||
                (node1->left && node2->right && node1->left->val == node2->right->val)) {
                q1.emplace(node1->right);
                q1.emplace(node1->left);
            } else {
                q1.emplace(node1->left);
                q1.emplace(node1->right);
            }
            q2.emplace(node2->left);
            q2.emplace(node2->right);
        }
        return q1.empty() && q2.empty();
    }
};
