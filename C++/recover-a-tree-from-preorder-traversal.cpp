// Time:  O(n)
// Space: O(h)
// iterative stack solution

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        vector<TreeNode *> stack;
        while (i < S.length()) {
            int j = S.find_first_not_of("-", i);
            int level = j - i;
            i = j;
            while (stack.size() > level) {
                stack.pop_back();
            }
            j = S.find_first_of("-", i);
            auto node = new TreeNode(stoi(S.substr(i, j - i)));
            i = j;
            if (!stack.empty()) {
                if (!stack.back()->left) {
                    stack.back()->left = node;
                } else{
                    stack.back()->right = node;
                }
            }
            stack.emplace_back(node);
        }
        return stack.front();
    }
};
