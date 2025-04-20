// Time Complexity: O(nlogn)
// Space Complexity: O(1)

class Solution {
    public:
        vector<Interval> merge(vector<Interval> &intervals) {
            vector<Interval> ans;
            sort(intervals.begin(), intervals.end(), 
                    [](const Interval &v1, const Interval &v2) { return v1.start < v2.start; }
                );
            const int n = intervals.size();
            for(int i = 0; i < n;) {
                ans.push_back(intervals[i++]);
                while(i < n && intervals[i].start <= ans.back().end)
                    ans.back().end = max(ans.back().end, intervals[i++].end);
            }
            return ans;
        }
};
