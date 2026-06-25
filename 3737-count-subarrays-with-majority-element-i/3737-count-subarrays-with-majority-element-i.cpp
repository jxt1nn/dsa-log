/*



    brute force 
    constraints are smol

    n2

    count the frequnecy of target 
    and check with the size of the subbar 

    if(freq > size/2){
        count++;
    }

*/
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;

        for(int i =0;i < nums.size();i++){
                int freq = 0;
            for(int j= i;j <nums.size();j++){
                if(nums[j] == target) freq++;
                int size = j-i+1;
                if(freq > (size/2)){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};