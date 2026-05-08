/*  

Return the number of integer points on the line that are covered with any part of a car

    start and end of the  car 
    
    points covered =  end - start + 1

we have to remove the overalapping problems and merge them into single interval....



like [3,6] and [1,5]

new interval will be [1,6] so the points are 6-1+1 = 6

how can we do this?????????

sort them by start..........

[[1,5],[3,6],[4,7]]

if(newstart < prevEnd){
    prevEnd =  newEnd
}

we add prevEnd - prevSart + 1

*/
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int start = nums[0][0];
        int end = nums[0][1];

        int ans = 0;
    
        for(int i = 1; i < nums.size();i++){
            int newS = nums[i][0];
            int newE = nums[i][1];

            //overLap
            if(newS <= end){
                end = max(newE,end);
            }
            // no overlap
            else{
                ans += (end - start + 1);
                start = newS;
                end = newE;
            }
        }
        // last intreval 
        ans += end - start + 1;
        return ans;
    }
};