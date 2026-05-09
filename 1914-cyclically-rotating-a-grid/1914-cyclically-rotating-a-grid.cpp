/*

    matrix is divided into layers.............

    outer boundary = layer 1
    inner boundary = layer 2
    then continue inward

---------------------------------------------------------

    Example:

    1  2  3  4
    5  6  7  8
    9 10 11 12
    13 14 15 16

---------------------------------------------------------

    Layers:

    outer:
    1 2 3 4 8 12 16 15 14 13 9 5

    inner:
    6 7 11 10

---------------------------------------------------------

    so problem is NOT rotating whole matrix

    we rotate EVERY layer independently

---------------------------------------------------------

    how layer boundaries are formed..........

    top row
    bottom row
    left column
    right column

---------------------------------------------------------

    initially:

    top    = 0
    bottom = m-1
    left   = 0
    right  = n-1

---------------------------------------------------------

    after finishing one layer:

    top++
    bottom--
    left++
    right--

    this moves us to next inner layer

---------------------------------------------------------

    now understand ONE cyclic rotation..........

    statement says:

        rotate counter-clockwise

    sounds hard................

---------------------------------------------------------

    think of layer as ARRAY

    Example outer layer:

    [1,2,3,4,8,12,16,15,14,13,9,5]

---------------------------------------------------------

    one rotation becomes:

    [2,3,4,8,12,16,15,14,13,9,5,1]

---------------------------------------------------------

    this is simply LEFT ROTATION by 1

---------------------------------------------------------

    so actual problem becomes:

        extract layer
        rotate array
        put back

---------------------------------------------------------
    HOW TO EXTRACT ONE LAYER..............

    Example matrix:

    1  2  3  4
    5  6  7  8
    9 10 11 12
    13 14 15 16

---------------------------------------------------------

    boundaries:

        top    = 0
        bottom = 3
        left   = 0
        right  = 3

---------------------------------------------------------

    STEP 1 : top row

    move left ---> right

    extracted:
        1 2 3 4

*/

// for(int j = left; j <= right; j++) {
//     layer.push_back(grid[top][j]);
// }

/*

---------------------------------------------------------

    STEP 2 : right column

    move top+1 ---> bottom

    extracted:
        8 12 16

    top+1 because
    4 already taken

*/

// for(int i = top + 1; i <= bottom; i++) {
//     layer.push_back(grid[i][right]);
// }

/*

---------------------------------------------------------

    STEP 3 : bottom row

    move right-1 ---> left

    extracted:
        15 14 13

    right-1 because
    16 already taken

*/

// for(int j = right - 1; j >= left; j--) {
//     layer.push_back(grid[bottom][j]);
// }

/*

---------------------------------------------------------

    STEP 4 : left column

    move bottom-1 ---> top+1

    extracted:
        9 5

    bottom-1 because
    13 already taken

    top+1 because
    1 already taken

*/

// for(int i = bottom - 1; i > top; i--) {
//     layer.push_back(grid[i][left]);
// }

/*

---------------------------------------------------------

    FINAL EXTRACTED LAYER:

    [1,2,3,4,8,12,16,15,14,13,9,5]

---------------------------------------------------------

    after layer extraction:

        top++
        bottom--
        left++
        right--

    move to next inner layer


---------------------------------------------------------
    how to roatate the array......

    left rotate using reverse method

     Example:

            arr = [1 2 3 4 5 6]
            k = 2

            reverse first k:
            [2 1 3 4 5 6]

            reverse remaining:
            [2 1 6 5 4 3]

            reverse whole:
            [3 4 5 6 1 2]

---------------------------------------------------------

    why k can be huge................

    suppose:

    len = 12
    k   = 100000

---------------------------------------------------------

    after every FULL cycle,
    layer becomes same again

---------------------------------------------------------

    so we only need:

    effectiveRotation = k % len

---------------------------------------------------------

    MAIN INTUITION :

    convert difficult 2D movement

                into

    easy 1D array rotation

---------------------------------------------------------

    final mental model:

    for every layer:

        extract elements
        rotate by k
        place back into matrix

*/
class Solution {
public:

    // reverse helper
    void reverseArray(vector<int>& arr, int l, int r) {

        while(l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    // left rotate using reverse method
    void leftRotate(vector<int>& arr, int k) {

        int n = arr.size();

        k = k % n;

        /*

            Example:

            arr = [1 2 3 4 5 6]
            k = 2

            reverse first k:
            [2 1 3 4 5 6]

            reverse remaining:
            [2 1 6 5 4 3]

            reverse whole:
            [3 4 5 6 1 2]

        */

        reverseArray(arr, 0, k - 1);

        reverseArray(arr, k, n - 1);

        reverseArray(arr, 0, n - 1);
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while(top < bottom && left < right) {

            vector<int> layer;

            //STEP 1 : extract layer

            // top row
            for(int j = left; j <= right; j++) {
                layer.push_back(grid[top][j]);
            }

            // right column
            for(int i = top + 1; i <= bottom; i++) {
                layer.push_back(grid[i][right]);
            }

            // bottom row
            for(int j = right - 1; j >= left; j--) {
                layer.push_back(grid[bottom][j]);
            }

            // left column
            for(int i = bottom - 1; i > top; i--) {
                layer.push_back(grid[i][left]);
            }

        
            //STEP 2 : rotate layer

            leftRotate(layer, k);

            
            // STEP 3 : put values back

            int idx = 0;

            // top row
            for(int j = left; j <= right; j++) {
                grid[top][j] = layer[idx++];
            }

            // right column
            for(int i = top + 1; i <= bottom; i++) {
                grid[i][right] = layer[idx++];
            }

            // bottom row
            for(int j = right - 1; j >= left; j--) {
                grid[bottom][j] = layer[idx++];
            }

            // left column
            for(int i = bottom - 1; i > top; i--) {
                grid[i][left] = layer[idx++];
            }

            // move inward
            top++;
            bottom--;
            left++;
            right--;
        }

        return grid;
    }
};