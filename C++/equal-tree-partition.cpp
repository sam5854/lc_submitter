// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> lookup;
        auto total = getSumHelper(root, &lookup);
        if (total == 0) {
            return lookup[total] > 1;
        }
        return total % 2 == 0 && lookup.count(total / 2);
    }

private:
    int getSumHelper(TreeNode* node,  unordered_map<int, int> *lookup) {
        if (!node) {
            return 0;
        }
        int total = node->val + 
                    getSumHelper(node->left, lookup) +
                    getSumHelper(node->right, lookup);
        ++(*lookup)[total];
        return total;
    }
};
