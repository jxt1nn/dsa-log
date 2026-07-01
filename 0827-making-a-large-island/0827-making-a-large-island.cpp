/*
    
    You are allowed to change at most one 0 to be 1.
    Return the size of the largest island in grid after applying this operation.
    An island is a 4-directionally connected group of 1s

    what if we randomly change a cellm 0 to 1???
    how to we know its neighbour size?????????????????

    left size + right size + up size + down size = island size
    
    but how we know this efficently??????????

    we know that we can only change 1 cell 
    and other cell remain same...............

    so we can connect the components.........

    SCREAMS!!!!!!!!!!!!!!!
    
            DSU

    step 1 :
        so we connenct all 1's by DSu (unionBYSize)

    step 2 : 
        
        then try to convert every 0 to one and calcuate island size
        by checking  size of its neighbour componants

    one BIG edge case:

        1 1 0 <-
        1 1 1
        0 1 0

    if try to conevert this 0 to one 
    it will add size of left and down 
        BUT they are same components..........
    
    
    so we can do one thing when check 4 directions......

    if we find a component we can add its ULTIMATE PARENT in SET data structure 
    SO,same component can't add mutiple times..............



    WE know that DSU works on arrray not grid structure 

    so we can assume every cell as a indecx

    formula:
        (row * m) + col
*/
class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int &i, int &j, int &n) {
        if (i < 0 || i >= n) return false;
        if (j < 0 || j >= n) return false;
        return true;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        //step 1 
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0) continue;

                for (int ind = 0; ind < 4; ind++) {

                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if (isValid(newRow, newCol, n) &&
                        grid[newRow][newCol] == 1) {

                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        //step 2
        int ans = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1) continue;

                set<int> components;

                for (int ind = 0; ind < 4; ind++) {

                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if (isValid(newRow, newCol, n) &&
                        grid[newRow][newCol] == 1) {

                        int nodeNumber = newRow * n + newCol;
                        components.insert(ds.findUPar(nodeNumber));
                    }
                }

                int sizeTotal = 0;

                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }

                ans = max(ans, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }

        return ans;
    }
};