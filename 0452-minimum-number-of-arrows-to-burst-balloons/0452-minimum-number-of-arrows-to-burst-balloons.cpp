/*

    xstart <= x <= xend.

    if intervals share a common point they will burst by one arrow 
    
    if(lastEnd >= intervals2.start) -> overlap.......
    
    points[i][0] > lastEnd -> not overlap


*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int lastEnd = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > lastEnd) {
                arrows++;
                lastEnd = points[i][1];
            }
        }

        return arrows;
    }
};