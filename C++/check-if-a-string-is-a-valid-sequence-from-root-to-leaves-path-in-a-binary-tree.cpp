// Time:  O(n)
// Space: O(w)
// bfs solution

class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        vector<TreeNode *> q = {root};
        for (int depth = 0; depth < arr.size(); ++depth) {
            vector<TreeNode *> new_q;
            while (!q.empty()) {
                const auto node = q.back(); q.pop_back();
                if (!node || node->val != arr[depth]) {
                    continue;
                }
                if (depth + 1 == arr.size() && node->left == node->right) {
                    return true;
                }
                new_q.emplace_back(node->left);
                new_q.emplace_back(node->right);            
            }
            q = move(new_q);
        }
        return false;
    }
};
