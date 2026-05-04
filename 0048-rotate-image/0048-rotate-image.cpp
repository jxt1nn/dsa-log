/*
transpose the matrix
then reverse every row










*/
class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        int n = A.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(A[i][j], A[j][i]);
            }
        }

        for(int i = 0; i < n; i++) {
            int left = 0, right = n - 1;

            while(left < right) {
                swap(A[i][left], A[i][right]);
                left++;
                right--;
            }
        }

    }
};