/*
    just taravers each column 
    and kkep the track of 
    -1 index 

    and max element

    after finishing the column just replace the -1 index value with max element


    how to do that??????????

    traverse the each column

    ohh there can be multiple -1 in a column

*/
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        int col = 0;

        while(col < c){
            int maxi = INT_MIN;
            vector<int> idx;
            for(int i =0; i <r;i++){
                if(m[i][col] == -1){
                    idx.push_back(i);
                }
                maxi = max(maxi,m[i][col]);
            }
            for(int i=0;i < idx.size();i++){   
                m[idx[i]][col] = maxi;
            }
            col++;
        }
        return m;    
    }
};