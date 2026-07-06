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

    Assume it is not covered.
    Compare it with every other interval j.
    If interval j covers interval i, mark i as covered and stop checking further.
    At the end, count how many intervals were not covered.


*/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int remaining = n;

        for (int i = 0; i < n; i++) {
            bool covered = false;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int a = intervals[i][0];
                int b = intervals[i][1];
                int c = intervals[j][0];
                int d = intervals[j][1];

                // Does intervals[j] cover intervals[i]?

                if (c <= a && b <= d) {
                    covered = true;
                    break;
                }
            }

            if (covered)
                remaining--;
        }

        return remaining;
    }
};