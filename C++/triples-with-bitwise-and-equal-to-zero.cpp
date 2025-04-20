// Time:  O(nlogn), n is the max of A
// Space: O(n)
// Reference: https://blog.csdn.net/john123741/article/details/76576925
// FWT solution

class Solution {
public:
    int countTriplets(vector<int>& A) {
        static const int k = 3;
        const auto max_A = *max_element(A.cbegin(), A.cend());
        int n = 1;
        for (; n <= max_A; n <<= 1);
        vector<int> B(n); 
        for (const auto& x : A) {
            ++B[x];
        }

        FWT(&B, 1);
        for(auto& x : B) {
            x = pow(x, k);
        }
        FWT(&B, -1);

        return B[0];
    }
    
private:
    void FWT(vector<int> *A, int v) {
        for (int d = 1; d < A->size(); d <<= 1) {
            for (int m = d << 1, i = 0; i < A->size(); i += m) {
                for (int j = 0; j < d ; ++j) {  
                    (*A)[i + j] += (*A)[i + j + d] * v;
                }
            }  
        }
    }
};
