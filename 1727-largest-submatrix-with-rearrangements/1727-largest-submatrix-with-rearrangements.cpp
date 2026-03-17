/*
    Is it a rectangle problem?
    YES

    Is it binary matrix?
    YES 

    Can I rearrange columns?
    YES

    its SCREAMS histogram + sorting problem 

    Especially in grids
    💡 Combine with binary → histogram almost guaranteed

    rectangle area : height * width 

    how can we convert this into histogram first????????

    
    histogram is nothing but height of a particular bar.......

    
    HOW TO CONVERT

    if(matrix[i][j] == 1) 
        h[j] += 1;
    else 
        h[j] = 0;

    when ever we incounter 0 in row the previuos height became zero

    example :

    matrix =
    1 0 1
    1 1 1
    1 1 0

    [1 0 1]
h = [1, 0, 1]

    [1 1 1]
h = [2, 1, 2]

    [1 1 0]
h = [3 2 0]

    Final Histograms:

        Row 0 → [1,0,1]
        Row 1 → [2,1,2]
        Row 2 → [3,2,0]

    this is our histogram for every row.........

    Each row = a histogram ✅

    now how to find the width of the rectangle???

    width of  particular index :
        we general find next smaller height and previous smaller height 

    BUT HERE IS A TWIST WE can rearrange the columns 

    means we can sort the histogram 
    SO our taller bars comes together and foam largest submatrix possible

    for every histogram row :
        sort in descending order.........

    find area for every bar :
        height =  h[i]
        width = i + 1       (i starts from 0)

    why we  take this  width

    BCOZ
    assume we are on height of 2 
    so we already sort it in desceinding order 
    
    SO their is always, greater height on its left 

    area = height * width = sh[j] * (j+1)
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> h(n, 0);
        int maxArea = 0;

        for(int i = 0; i < m; i++) {

            // Step 1: Build histogram
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1)
                    h[j] += 1;
                else
                    h[j] = 0;
            }

            // Step 2: Sort heights (descending)
            vector<int> sh = h;
            sort(sh.rbegin(), sh.rend());

            // Step 3: Calculate max area
            for(int j = 0; j < n; j++) {
                if(sh[j] == 0) break;
                maxArea = max(maxArea, sh[j] * (j + 1));
            }
        }

        return maxArea;
    }
};