/*
    we have a grid 

    determine if it is possible to make either one horizontal or one vertical cut

    The sum of the elements in both sections is equal

    how can we check that????
    
        only (605 testcase passed)
                            // we can do one thing :

                            // make two array 
                            //     1. for rows 
                            //         size-> (n)
                            //     2. for col 
                            //         size->(m)

                            // this two arrays store sum of every row and col

                            // then,

                            // traverse in this two array 
                            // two pointers:
                            //     i = 0
                            //     j = last element 

                            // simply check 
                            // while(i <= j)
                            // if(sum1 < sum2) 
                            //     i++;
                            // else if(sum1 > sum2){
                            //     j--;
                            // }else{
                            //     i++;
                            //     j--;
                            // }

                            // at the end check if sum1 == sum2 
                            // return true 
                            // else false 


    here is the actual logic...........

    when we can split???
    when total sum of matrix is EVEN...........

    if sum is EVEN what will satisfy it will cut or not???

    calculate sum for every row 
        and after calculting for a row

    check :
        rowSUM == totalSum / 2
        if YES -> true
    
    check same for col also 
        colSUM == totalSUM / 2
        if YES -> true

    at the end return false  

*/
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

          long long totalSUM = 0;

        // total sum
        for(auto &row : grid)
            for(int x : row)
                totalSUM += x;

        if(totalSUM % 2 != 0) return false;


        // horizontal cut
        long long rowSUM = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m; j++)
                rowSUM += grid[i][j];

            if(rowSUM == totalSUM / 2) return true;
        }

        // vertical cut
        long long colSUM = 0;
        for(int j = 0; j < m - 1; j++) {
            for(int i = 0; i < n; i++)
                colSUM += grid[i][j];

            if(colSUM == totalSUM / 2) return true;
        }

        return false;
    }
};

// row sum array
        // vector<long long> rowSum(n, 0);
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         rowSum[i] += grid[i][j];
        //     }
        // }

        // // col sum array
        // vector<long long> colSum(m, 0);
        // for(int j = 0; j < m; j++) {
        //     for(int i = 0; i < n; i++) {
        //         colSum[j] += grid[i][j];
        //     }
        // }

        // // check using two pointer on rowSum
        // long long sum1 = 0, sum2 = 0;
        // int i = 0, j = n - 1;

        // while(i <= j) {
        //     if(sum1 < sum2) {
        //         sum1 += rowSum[i++];
        //     } else if(sum1 > sum2) {
        //         sum2 += rowSum[j--];
        //     } else{
        //         sum1 += rowSum[i++];
        //         sum2 += rowSum[j--];
        //     }
        // }

        // if(sum1 == sum2) return true;

        // // check using two pointer on colSum
        // sum1 = 0, sum2 = 0;
        // i = 0, j = m - 1;

        // while(i <= j) {
        //     if(sum1 < sum2) {
        //         sum1 += colSum[i++];
        //     } else if(sum1 > sum2) {
        //         sum2 += colSum[j--];
        //     } else{
        //         sum1 += colSum[i++];
        //         sum2 += colSum[j--];
        //     }
        // }

        // return sum1 == sum2;