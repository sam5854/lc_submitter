// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> que;

        if (root != nullptr) {
            que.emplace(root);
        }

        while (!que.empty()) {
            vector<int> level;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                auto *front = que.front();
                que.pop();
                level.emplace_back(front->val);
                if (front->left != nullptr) {
                    que.emplace(front->left);
                }
                if (front->right != nullptr) {
                    que.emplace(front->right);
                }
            }
            result.emplace_back(move(level));
        }
        
        // The only difference between binary-tree-level-order-traversal
        // and binary-tree-level-order-traversal-ii
        reverse(result.begin(), result.end());
        
        return result;
    }
};
