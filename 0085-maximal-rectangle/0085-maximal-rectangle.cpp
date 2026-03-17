/*
    Is it a rectangle problem?
    YES 

    is it binary matrix?
    YES

    Can I rearrange columns?
    NO

    its SCREAMS histogram + stack problem 

    Especially in grids
    💡 Combine with binary → histogram almost guaranteed

    rectangle area : height * width 

    how can we convert this into histogram first????????

    histogram is nothing but height of a particular bar.......

    HOW TO CONVERT

    if(matrix[i][j] == 1) 
        h[j] += 1;
    else 
        h[j] = 0;

    when ever we incounter 0 in row the previuos height became zero

    example :

    matrix =
    1 0 1
    1 1 1
    1 1 0

    [1 0 1]
h = [1, 0, 1]

    [1 1 1]
h = [2, 1, 2]

    [1 1 0]
h = [3 2 0]

    Final Histograms:

        Row 0 → [1,0,1]
        Row 1 → [2,1,2]
        Row 2 → [3,2,0]

    this is our histogram for every row.........

    Each row = a histogram ✅

    now how to find the width of the rectangl???

    for each index :

        we have to know its 

    NEXT SMALLER HEIGHT
    and 
    PREVIOUS SMALLER HEIGHT 

    we can easily find this by montonic stack
    PSE and NSE

    “New row = new histogram = new PSE/NSE”

    LESSSSGOOOOOOOOOOOOO!!!!!!!!!!
*/
class Solution {
public:
      vector<int> getNSL(vector<int>& arr, int n){
        stack<int> st;
        vector<int> result(n);
        
        // next smaller to left

        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()) result[i] = -1;
            else{
                result[i] = st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int> getNSR(vector<int>& arr, int n){
        stack<int> st;
        vector<int> result(n);
        
        //next smaller to right

        for(int i =n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) result[i] = n;
            else{
                result[i] = st.top();
            }
            st.push(i);
        }
        return result;
    }
    int getArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);

        int MaxArea = INT_MIN;
        for(int i =0;i<n;i++){

            int width = NSR[i] - NSL[i] - 1; 

            int area = arr[i] * width;
            MaxArea = max(area, MaxArea);

        }
        return MaxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //col

        vector<int> height(n);

        for(int i =0;i<n;i++){
            height[i] = (matrix[0][i] == '1')? 1 : 0;     //push first row 
        }

        int MaximumArea = getArea(height); // first row area 
     
        // find remaining row histogram 
        // and thier area
        
        for(int i = 1 ;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == '0') height[j] = 0; 
                else height[j] += 1;
            }
            MaximumArea = max(MaximumArea,getArea(height));
        }
        return MaximumArea;
    }
};