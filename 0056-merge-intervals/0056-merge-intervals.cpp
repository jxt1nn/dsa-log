/*
    merge all overlapping intervals,
    return an array of the non-overlapping intervals that cover
    intervals in the input all the intervals in the input.

    how to check 2 intervals overlap or not???????
    they should be in sorted manner 

    SO SORT THE ARRAY 
    now check :
    
    if(interval2.start <= interval1.end) → overlap
    -> they overlap

    otherwise not

    and one more thing if they overlap 
    we cannot just put them into result array 
    we have too  Keep expanding Interval


    [[1,4],[4,5]] they oberlap

    how to make a common non obverlapping interval :

        new.start = min(new.start, interval.start)
        new.end   = max(new.end, interval.end)

    and when we create a new interavl
        do not add immedatily

    example 

    [[1,3],[2,6],[6,10],[15,18]]

    [1,3][2,6][6,10] -> overalap    

    how make a simgle interval
    first for 
    [1,3][2,6] -> [1,6]
    then : 
    [1,6][6,10] -> [1,10]


   Two cases:

    🟢 Overlap 
        next.start <= curr.end
    👉 Merge:
        curr.end = max(curr.end, next.end)
    
    we dont need to compute curr.start  
        bcoz our array is already sorted so
        curr.start is always same either they overlap or not !!!!!!!


    🔵 No overlap
        next.start > curr.end
    👉 Push curr to answer
    👉 Start new interval

    Sort → Keep current → Expand if overlap → Push when break
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        // Step 2: Start with first interval
        vector<int> curr = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            
            // Overlap
            if (intervals[i][0] <= curr[1]) {
                curr[1] = max(curr[1], intervals[i][1]);
            }
            // No overlap
            else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        
        // Last interval push karna mat bhoolna
        ans.push_back(curr);
        
        return ans;
    }
};