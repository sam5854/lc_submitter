// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end(), greater<int>());
        const auto max_arr = arr[0];
        while (!arr.empty() && arr.back() * arr.size() <= target) {
            target -= arr.back(); arr.pop_back();
        }
        // let x = ceil(t/n)-1
        // (1) (t/n-1/2) <= x:
        //    return x, which is equal to ceil(t/n)-1 = ceil(t/n-1/2) = (2t+n-1)//2n
        // (2) (t/n-1/2) > x:
        //    return x+1, which is equal to ceil(t/n) = ceil(t/n-1/2) = (2t+n-1)//2n
        // (1) + (2) => both return (2t+n-1)//2n
        return arr.empty() ? max_arr : (2 * target + arr.size() - 1) / (2 * arr.size());
    }
};
