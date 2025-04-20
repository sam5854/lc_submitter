// Time:  O(n)
// Space: O(h)

class Solution {
public:
    TreeNode* str2tree(string s) {
        int i = 0;
        return s.empty() ? nullptr : str2treeHelper(s, &i);
    }

private:
    TreeNode* str2treeHelper(const string& s, int *i) {
        auto start = *i;
        if (s[*i] == '-') {
            ++(*i);
        }
        while (*i < s.length() && isdigit(s[*i])) {
            ++(*i);
        }
        
        auto node = new TreeNode(stoi(s.substr(start, *i - start)));
        if (*i < s.length() && s[*i] == '(') {
            ++(*i);
            node->left = str2treeHelper(s, i);
            ++(*i);
        }
        if (*i < s.length() && s[*i] == '(') {
            ++(*i);
            node->right = str2treeHelper(s, i);
            ++(*i);
        }
        return node;
    }
};
