class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });
        int res = 0, prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd)
                res++;
            else
                prevEnd = intervals[i][1];
        }
        return res;
    }
};