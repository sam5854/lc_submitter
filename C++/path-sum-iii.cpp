// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {        
        unordered_map<int, int> lookup;
        lookup[0] = 1;
        return pathSumHelper(root, 0, sum, &lookup);
    }

private:
    int pathSumHelper(TreeNode* root, int curr, int sum, unordered_map<int, int> *lookup) {
        if (!root) {
            return 0;
        }
        curr += root->val;
        int result = lookup->count(curr - sum) ? (*lookup)[curr - sum] : 0;
        ++(*lookup)[curr];
        result += pathSumHelper(root->left, curr, sum, lookup) + pathSumHelper(root->right, curr, sum, lookup);
        --(*lookup)[curr];
        if ((*lookup)[curr] == 0) {
            lookup->erase(curr);
        }
        return result;
    }
};
