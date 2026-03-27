/*
    we have a n * m matrix 
        and we haev to return a matrix 

    which have is the product matrix of matrix given to us......

    Each element result[i][j] is calculated as the product
    of all elements in grid except for the element grid[i][j]
   
    This product is then taken modulo 12345.

    if we do 
        totalProcuct / mat[i][j] % 12345

    totalProduct = product of all elements
        This can become very huge (overflow) even before modulo
    
    We solve it like "Product of Array Except Self"

    👉 Instead of division, use:
        Prefix product
        Suffix product

    Convert 2D → 1D array
    Step 2: Build prefix array
    Step 3: Build suffix array

    result[i] = prefix[i] * suffix[i] % 12345

    Step 5: Convert back to 2D

    🔥 When You See This Pattern

    If problem says
        “Product of all elements except itself”

        💡 Immediately think:
        👉 Prefix + Suffix (NO division)
    */
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int size = n * m;

        vector<int> arr;
        for (auto &row : grid) {
            for (int x : row) {
                arr.push_back(x % 12345);
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        // prefix
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % 12345;
        }

        // suffix
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % 12345;
        }

        vector<vector<int>> result(n, vector<int>(m));

        for (int i = 0; i < size; i++) {
            int val = (prefix[i] * suffix[i]) % 12345;
            result[i / m][i % m] = val;
        }

        return result;
    }
};