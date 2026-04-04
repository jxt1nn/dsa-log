/*
    what happen during encoding???
        fill matrix diagonally (↘)
        Start from (row=0, col=0)
        Move down-right
        When you go out of rows → start next column

    So pattern looks like:
    (0,0)
    (1,1)
    (2,2)

    Then restart from next column:
    (0,1)
    (1,2)
    (2,3)
    ...

    then: 

    Read matrix row-wise
        Left → Right
        Row by row

    what are we given?
        encodedText (row-wise output)
        rows

    we need to reverse the process

    intution..........

    can we reconstruct the matrix FIRST!!!!!!!!!!!!

    we know the matrix rows 
        but col?????

    cols = encodedText.length / rows

    Now fill matrix:

        row 0 → first 'cols' chars  
        row 1 → next 'cols' chars  
        ...

    Now reverse diagonal reading
        Original string was written diagonally ↘
    
    So to recover it:
        Start from every column in row 0
        move diagonally (i+1, j+1)


    example:
        encodedText = "ch ie pr"
        rows = 3

    Matrix:
    
       c h _ _
        i e _ _
        _ p r _

    Now read diagonally:

    Start from col 0:
        (0,0) → c
        (1,1) → e
        (2,2) → r

    Start from col 1:
        (0,1) → h
        (1,2) → _

    Start from col 2:
        (0,2) → _

    Combine → "cipher"
*/
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 0) return "";
        
        int n = encodedText.size();
        int cols = n / rows;
        
        vector<vector<char>> mat(rows, vector<char>(cols));
        
        // Fill matrix row-wise
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[idx++];
            }
        }
        
        string result = "";
        
        // Read diagonally
        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                result += mat[i][j];
                i++;
                j++;
            }
        }
        
        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};