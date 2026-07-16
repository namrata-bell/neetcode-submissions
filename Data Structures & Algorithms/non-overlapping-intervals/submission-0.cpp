class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
//imp
        int removed = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) {
                // No overlap
                prevEnd = intervals[i][1];
            } else {
                // Overlap
                removed++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }

        return removed;
    }
};