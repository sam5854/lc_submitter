// Time:  O(n)
// Space: O(h)
// Definition for a Node.
// one pass solution without recursion

class Solution {
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        unordered_map<Node *, Node *> lookup;
        const auto& is_ancestor = iter_find_parents(root, nullptr, p, q, false, &lookup);
        if (lookup.count(p) && lookup[p] == q) {
            return root;
        }
        q->children.emplace_back(p);
        if (!is_ancestor) {
            lookup[p]->children.erase(find(begin(lookup[p]->children), end(lookup[p]->children), p));
        } else {
            lookup[q]->children.erase(find(begin(lookup[q]->children), end(lookup[q]->children), q));
            if (p == root) {
                root = q;
            } else {
                *find(begin(lookup[p]->children), end(lookup[p]->children), p) = q;
            }
        }
        return root;
    }

private:
    bool iter_find_parents(Node *node, Node *parent, Node *p, Node *q,
                           bool is_ancestor,
                           unordered_map<Node *, Node *> *lookup) {
        vector<tuple<int, Node *, Node *, bool, int>> stk = {tuple(1, node, parent, is_ancestor, -1)};
        while (!stk.empty()) {
            const auto [step, node, parent, is_ancestor, i] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (node == p || node == q) {
                    (*lookup)[node] = parent;
                    if (lookup->size() == 2) {
                        return is_ancestor;
                    }
                }
                stk.emplace_back(2, node, parent, is_ancestor, node->children.size() - 1);
            } else {
                if (i < 0) {
                    continue;
                }
                stk.emplace_back(2, node, parent, is_ancestor, i - 1);
                stk.emplace_back(1, node->children[i], node, is_ancestor || node == p, -1);
            }
        }
        assert(false);
        return false;
    }
};
