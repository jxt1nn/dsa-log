/*
    we have n / n matrix

    one step you can choose two adjacent rows of the grid and swap them.

    A grid is said to be valid if all the cells above the main diagonal are zeros.

    what is main digaonal?
    like 
    (0,0), (1,1), (2,2), ..., (n-1,n-1)

        anything where (i,j) is same 

    main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n,n)

    Cells above diagonal means: (row < col)
        (0,1) (0,2)
            (1,2)

    Row 0 → columns 1,2,... must be 0
    Row 1 → columns 2,3,... must be 0
    Row 2 → columns 3,4,... must be 0

    Row i must have no 1s after index i

    Swap two adjacent rows

    That means:
        You cannot rearrange freely
        You can only bubble rows up/down (like bubble sort)

    So the problem becomes:
        Reorder rows so that row i has at least (n - i - 1) trailing zeros

    For row position i : trailingZeros >= (n - i - 1)

    Because:
        Row 0 needs n-1 zeros
        Row 1 needs n-2 zeros
        Row 2 needs n-3 zero

    We go row by row (from top).

    For each position i:
        Find a row at or below i
        That satisfies required trailing zeros
        Bring it up using adjacent swaps
        Count swaps
        If no such row exists → return -1

    For each i:

        Search from i to n-1
        Find first row with enough trailing zeros
        If found at index j
            Swap it upward until it reaches i
            Add (j - i) to answer
        If not found → impossible


        
        [0,0,1],
        [1,1,0],
        [1,0,0]

        Trailing zeros:
            Row0 → 0
            Row1 → 1
            Row2 → 2

        Requirements:
            Row0 needs 2
            Row1 needs 1
            Row2 needs 0
    
    Step:
        For row0 → need 2 → pick row2 → swap up (2 swaps)
     
     
        [0,0,1],
        [1,0,0],   ← row2 moved up one
        [1,1,0]

        
        [1,0,0],   ← correct row at top now
        [0,0,1],
        [1,1,0]
        
    Now row0 position is satisfied ✅

    That’s why we count: j - i

        It was at index 2
        We want it at index 0
        So we need 2 adjacent swaps

    If row is at index j
    And we want it at index i

    So number of swaps = j - i

    Swap row2 with row1:

    Total swaps so far:
    2 (previous) + 1 = 3
**/
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Step 1: Count trailing zeros for each row
        vector<int> trailing(n, 0);
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            trailing[i] = count;
        }
        
        int swaps = 0;
        
        // Step 2: Fix each row one by one
        for (int i = 0; i < n; i++) {
            int required = n - i - 1;
            
            int j = i;
            
            // Find first row that satisfies requirement
            while (j < n && trailing[j] < required) {
                j++;
            }
            
            // If no such row exists → impossible
            if (j == n)
                return -1;
            
            // Bring row j to position i using swaps
            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                j--;
                swaps++;
            }
        }
        
        return swaps;
    }
};