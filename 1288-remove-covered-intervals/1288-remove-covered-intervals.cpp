/*

    we have intervals and we have to remove 
    all the covered intervals that 
    statisfy this 2 conditionn..............

    [a, b) is covered by the interval [c, d) :  if and only if 
    
                    c <= a and b <= d.

    for every interval i
        for every interval j
            if (j covers i)
                remove i



*/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int remaining = 0;

        for (int i = 0; i < n; i++) {
            bool covered = false;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                // Does intervals[j] cover intervals[i]?
                if (intervals[j][0] <= intervals[i][0] &&
                    intervals[i][1] <= intervals[j][1]) {
                    covered = true;
                    break;
                }
            }

            if (!covered)
                remaining++;
        }

        return remaining;
    }
};