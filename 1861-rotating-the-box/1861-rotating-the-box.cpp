/*
    think like every row as a array 

    and in this array we have to chnge the position of stones 

    obstacles doesnt change their position

    so we have 2 type of stoping points :
        end of the array and obstracle........

    
    we start from back of the array and mark stop point is n-1 
    if n-1 have already a stone or obstacle 
    we move left till we dosent find empty space 
    adjacnet to obstacle or stone 

    then this is our stop point
    now comes the good part 

    check left of stop point 
    if we found any stone 
    its new position is stop point
    and we have to go to new stop point 

    and if we find a obstacles 
    before a stone 
    our new stop point lies in left side of the stone..............


    A stone : '#'
    A stationary obstacle : '*'
    Empty : '.'
    
    ["#",".","#"]

    Traverse from right → left
    stop = last position where stone can fall

    If * found
    stop = i - 1

    If # found
    swap(box[row][i], box[row][stop])
    stop--

    If .
    → do nothing


    doing same process for every row

    then:
        Original (i, j)
    Rotate 90° Clockwise → New position ( ?, ? )

    Original (3 x 3):

    a b c
    d e f
    g h i

    After 90° clockwise rotation:

    g d a
    h e b
    i f c

    Take a:
    Original position → (0, 0)
    New position → (0, 2)

    Take b:
    (0,1) → (1,2)

    Take d:
    (1,0) → (0,1)

    We observe:
    (i, j) → (j, m - 1 - i)
    m = number of rows

    result[j][m - 1 - i] = box[i][j];


    same as 
    transpose then reverse each row

    (i, j)
    → (j, i)        // transpose
    → (j, m-1-i)    // reverse row

*/
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        //simulate gravity (right side)
        for (int i = 0; i < m; i++) {
            int stop = n - 1; // last position

            for (int j = n - 1; j >= 0; j--) {

                if (box[i][j] == '*') {
                    stop = j - 1; // reset stop
                }

                else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][stop]);
                    stop--;
                }
            }
        }

        //rotate matrix 90° clockwise
        vector<vector<char>> result(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = box[i][j];
            }
        }

        return result;
    }
};