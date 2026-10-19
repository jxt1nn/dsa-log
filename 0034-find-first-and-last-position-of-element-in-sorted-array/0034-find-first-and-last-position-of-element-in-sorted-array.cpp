class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left_idx = lowerBound(nums,target);
        int right_idx = upperBound(nums,target) - 1;
        
        if(left_idx == nums.size() || nums[left_idx] != target) return {-1,-1};
        return {left_idx,right_idx};

    }

    int lowerBound(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int idx = nums.size();

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                idx = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
         }
         return idx;
    }
    int upperBound(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int idx = nums.size();

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] > target){
                idx = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return idx;
    }
};