// Time:  O(n + l)
// Space: O(h + l)
// kmp solution

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) {
            return true;
        }
        const auto& [pattern, prefix] = getPrefix(head);
        return dfs(pattern, prefix, root, -1);
    }

private:
    bool dfs(const vector<int>& pattern,
             const vector<int>& prefix,
             TreeNode *root, int j) {
        if (!root) {
            return false;
        }
        while (j + 1 && pattern[j + 1] != root->val) {
            j = prefix[j];
        }
        if (pattern[j + 1] == root->val) {
            ++j;
        }
        if (j + 1 == pattern.size()) {
            return true;
        }
        return dfs(pattern, prefix, root->left, j) ||
               dfs(pattern, prefix, root->right, j);
    }
    
    pair<vector<int>, vector<int>> getPrefix(ListNode *head) {
        vector<int> pattern = {head->val};
        vector<int> prefix = {-1};
        int j = -1;
        auto node = head->next;
        while (node) {
            while (j + 1 && pattern[j + 1] != node->val) {
                j = prefix[j];
            }
            if (pattern[j + 1] == node->val) {
                ++j;
            }
            pattern.emplace_back(node->val);
            prefix.emplace_back(j);
            node = node->next;
        }
        return {pattern, prefix};
    }
};
