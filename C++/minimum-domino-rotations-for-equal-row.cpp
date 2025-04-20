// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        set<int> intersect{A[0], B[0]};
        for (int i = 1; i < A.size() && !intersect.empty(); ++i) {
            const auto s1 = move(intersect);
            const set<int> s2{A[i], B[i]};
            set_intersection(s1.cbegin(), s1.cend(),
                             s2.cbegin(), s2.cend(),
                             inserter(intersect, intersect.begin()));
        }
        if (intersect.empty()) {
            return -1;
        }
        const auto& x = *intersect.cbegin();
        return min(A.size() - count(A.cbegin(), A.cend(), x),
                   B.size() - count(B.cbegin(), B.cend(), x));
    }
};
