/*
    we have m * n matrix 
    three integers x, y, and k.
    
    x and y represent :
        row and column indices of the top-left corner of a square submatrix

    k represents:
        the size (side length) of the square submatrix

    k → size of square
        means new squre will be k * k

    
    we have to go mat[x][y] then find the length of new matrix

    yea we can do one thing

    instead of going on that index 
        just start from their bcoz we already have that index 

    for(row -> x to x + ( k-1 )){
        for(col -> y to y+(k-1))

    }
    now just swap the elements..........

    how 

    row 1 ↔ row n
    row 2 ↔ row n-1
    row 3 ↔ row n-2

    Loop idea:

    Use two pointers:
        top = x
    
    bottom = x + k - 1
        While top < bottom:
    Swap elements column-wise from y → y + k - 1

*/
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int top = x;
        int bottom = x + k - 1;
        
        while(top < bottom) {
            for(int col = y; col < y + k; col++) {
                swap(grid[top][col], grid[bottom][col]);
            }
            top++;
            bottom--;
        }
        
        return grid;
    }
};