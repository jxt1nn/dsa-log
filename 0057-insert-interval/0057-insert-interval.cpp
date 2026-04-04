/*
    intervals = sorted, non-overlapping
    newInterval = [start, end]

    what we have to do :    
    Insert it
    Keep sorted
    Merge overlaps if needed

    every interval will fall into one of 3 cases:

    🟢 Case 1: Completely BEFORE newInterval

    if(interval.end < new.start)
        no overlap
        just add as it is 

    🔴 Case 2: OVERLAPPING

        interval.start <= new.end
Merge them:
        new.start = min(new.start, interval.start)
        new.end   = max(new.end, interval.end)

    Keep expanding newInterval

    🔵 Case 3: Completely AFTER newInterval

        interval.start > new.end
        No more overlap possible (IMPORTANT!)
        Add newInterval first, then remaining intervals


    1. Add all safe intervals (left side)
    2. Merge all overlapping into ONE interval
    3. Add rest (right side)



*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        
        //1. Add all before
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        //2. Merge overlaps
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        ans.push_back(newInterval);
        
        //3. Add remaining
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};