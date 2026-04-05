/*
    return the minimum number of intervals you need to remove
    to make the rest of the intervals non-overlapping.

    Note :
    that intervals which only touch at a point are non-overlapping.
    
    For example, [1, 2] and [2, 3] are non-overlapping.

    means if 2 intervals have same start and end time they are non-overlapping

    how can we remove it???

    can we check :
        Keep maximum number of non-overlapping intervals

    then :
        answer = total intervals - kept intervals


    how can we count number of non-overlapping intervals?????

    sort them by end time

    then check 
    if intervals[i][0] >= prev_end
    this is a non-ovrelapping intervals
    
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        // Step 1: Sort by end time
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        // Step 2: Count how many we can KEEP
        int kept = 1; // first interval always kept
        int prev_end = intervals[0][1];
        
        for (int i = 1; i < n; i++) {
            
            // No overlap → we can keep it
            if (intervals[i][0] >= prev_end) {
                kept++;
                prev_end = intervals[i][1];
            }
        }
        
        // Step 3: Remove = total - kept
        return n - kept;
    }
};