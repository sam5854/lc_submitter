// Time:  O(n)
// Space: O(h)
// morris traversal

class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        unordered_map<char, int> count;   
        char prev = '+';
        morrisInorderTraversal(root1, bind(&Solution::addCounter, this,
                                           &count, &prev, 1, placeholders::_1));
        prev = '+';
        morrisInorderTraversal(root2, bind(&Solution::addCounter, this,
                                           &count, &prev, -1, placeholders::_1));
        return all_of(cbegin(count), cend(count),
                      [](const auto& kvp) {
                          return kvp.second == 0;
                      });
    }

private:
    void morrisInorderTraversal(Node *root, const function<void(char)>& cb) {
        auto curr = root;
        while (curr) {
            if (!curr->left) {
                cb(curr->val);
                curr = curr->right;
            } else {
                auto node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    cb(curr->val);
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
    }
    
    void addCounter(unordered_map<char, int> *count, char *prev, int d, char val) {
        if (isalpha(val)) {
            (*count)[val] += (*prev == '+') ? d : -d;
        }
        *prev = val;
    }
};
