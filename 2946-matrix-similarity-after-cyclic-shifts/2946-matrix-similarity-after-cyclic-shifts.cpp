/*
    we have a m * n matrix and intege K 

    for even index : 
        do left shift K times 

    for odd index:
        do right shift K times

    what left shift means ????????

        the front element of row goes to back of the row
            (do this same step K times)

    what right shift means ???
        the back element of row goes to front of the row
            (do this same step K times)

    but wait....

    what if... row size < K 

    number of element left shirft OR right shift = K % row.size

    we know how many elemnt should be consider for left and right shift......

    how can we do this efficently...

    constraints is smol...

    for left shift :

    we can reverse the element from :
        k+1 to n 
    then :
        reverse the full row

    for right shift :

    we can reverse the element from :

        from back :
        n to k-1

    then : 
        reverse thee full row 

    do left shift for : 0,2,4,6....

    do right shift for: 1,3,5,7.....


    WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

    we dont need to return any matrix....LOL

    we need to return true or false 

    Return true if the final modified matrix 
    after k steps is identical to the original matrix, and false otherwise

    just check :
        if(k % n == 0) return true;
        else false

    bcoz if mod is 0 we have no need to left or right shift it remain same

    BUt here is a one edge case comes.........

    what if row have same element 

        we check for each row :

    if (all same elemnet) can do left or right shift
    else simply return false
    bcoz its not possible to reamin identical 


    NOOOOOOOOOOOOOOOOO

    [[1,2,1,2],[5,5,5,5],[6,3,6,3]] k = 2 
    see this example

    our logic doesnt work here 

    so simple logic now...

    just check after left shift is our matrix remain same or not

    for left shift :  mat[i][j] != mat[i][(j + k) % n]
        Left shift moves elements forward
        Wrap around using % n


    for right shift : mat[i][j] != mat[i][(j - k % n + n) % n]
        Right shift moves backward
        j - k may become negative 
        So we add + n to make it positive 
        Then % n to wrap around
*/   
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i % 2 == 0) {
                    // left shift
                    if(mat[i][j] != mat[i][(j + k) % n])
                        return false;
                } else {
                    // right shift
                    if(mat[i][j] != mat[i][(j - k % n + n) % n])
                        return false;
                }
            }
        }
        return true;
    }
};