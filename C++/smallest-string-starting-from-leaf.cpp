// Time:  O(n + l * h), l is the number of leaves
// Space: O(h)

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string result = "~";
        string candidate;
        dfs(root, &candidate, &result);
        return result;
    }
    
private:
    void dfs(TreeNode *node, string *candidate, string *result) {
        if (!node) {
            return;
        }

        candidate->push_back('a' + node->val);
        if (!node->left && !node->right) {
            *result = min(*result, string(candidate->rbegin(), candidate->rend()));
        }
        dfs(node->left, candidate, result);
        dfs(node->right, candidate, result);
        candidate->pop_back();
    }
};
