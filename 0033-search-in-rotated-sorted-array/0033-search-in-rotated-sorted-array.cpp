/*

    we cannot find target directly 

    we have roated sorted array :
    means 
    WE have 2 sorted array 

    l.....h | l.......h

    we can choose in betwwen them and try to find our target 

    how we seprate them 
    find the minumum elemnt in array 

    [4,5,6,7,0,1,2]

    like 0 
    (LOGIC : Find Minimum in Rotated Sorted Array)
    
    then we have the index of minimum element 
    then cut down the serach space and
    use BINARY SEARCH ON IT....


*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low != high){

            int mid = (low+high) / 2;

            if(nums[mid] > nums[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }


        int pivot = low;

        if (nums[pivot] == target)
            return pivot;

        int l, h;
        int n = nums.size();

        // Decide search space
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            l = pivot;
            h = n - 1;
        }
        else {
            l = 0;
            h = pivot - 1;
        }


        while(l <= h){
            int mid = (l+h)/2;

            if(nums[mid] == target) return mid;
            
            if(nums[mid] < target){
                l = mid+1;
            }
            else if(nums[mid] > target){
                h = mid-1;
            }
        }
        return -1;
    } 
};