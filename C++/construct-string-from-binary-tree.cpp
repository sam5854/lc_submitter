// Time:  O(n)
// Space: O(h)

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) {
            return "";
        }

        auto s = to_string(t->val);

        if (t->left || t->right) {
            s += "(" + tree2str(t->left) + ")";
        }
        
        if (t->right) {
            s += "(" + tree2str(t->right) + ")";
        }

        return s;
    }
};
