/*
    
    array is sorted in desecnding order...........

    left side always greater and right side always lower

    if we choose 9 from nums1 
    we can consider all element <= 9
    where j >= i

    nums[j] >= nums[i]
    j >= i

    when did we get maximum distance????????????

    Fix an index i in nums1
    Try to go as far right as possible in nums2 (increase j)

    Bigger j ⇒ bigger distance
    j - i


    Both arrays are non-increasing (descending):
    nums1: 10 8 6 4
    nums2: 12 9 7 5

    That means:
    As index increases → values decrease

    Core intuition
    For each i:

    Try to find the farthest j (j ≥ i) such that
    nums2[j] >= nums1[i]

    why farthest???????
    Because we want max (j - i)

    Brute:

    for i
    for j from i → end

    → O(n²) HELL NAHHHHHHHHH

    // old solution two pointers 
    // Because arrays are sorted (non-increasing):
        
    //     if condition fails once, it will keep failing further
    //     if condition works, you can try to push j further


    // if(nums2[j] >= nums1[i]){
    //     we can try to expand j
    // }
    // else{
    //     we cannot go right becoz it will give us smaller 
    //     numbers beacuse of non-decreasing......

    //     so what we can do incerase the j
    // }

    // two pointers.....
    // i = 0
    // j = 0

        // "For every i, push j as far as possible while condition holds"

    (binary search):

    for each i, we directly find the farthest valid j   

    For a fixed i, we want:
    the maximum j (j ≥ i) such that:

    nums2[j] >= nums1[i]

    nums2 is non-increasing (descending):

    9 8 7 6 5

    So:

    Left side → bigger values
    Right side → smaller values

    Condition nums2[j] >= nums1[i] will be:

    TRUE TRUE TRUE FALSE FALSE

    We want:
    the last index where condition is TRUE

Search in range:

j ∈ [i, nums2.size()-1]

    

    9 8 7 6 4 2 1

    i = 0
    left = i , right = n-1 and nums[i] = 1

    mid = 3(6)
    
    if(nums[mid] >= nums[i]){
        bext = mid
        left = mid+1
    }
    else{
        right = mid - 1;
    }

    if(best >= i){
        maxi = max(maxi ,best - i)
    }

    "For each i, binary search the farthest j where condition holds"



*/
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int maxi = 0;

        for(int i = 0; i < m; i++) {
            int left = i, right = n - 1;
            int best = i - 1; // means no valid j yet

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(nums2[mid] >= nums1[i]) {
                    best = mid;        // valid
                    left = mid + 1;   // try to go further right
                } else {
                    right = mid - 1;  // go left
                }
            }

            if(best >= i) {
                maxi = max(maxi, best - i);
            }
        }

        return maxi;
    }
};
// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0, j = 0;
//         int maxi = 0;

//         while(i < nums1.size() && j < nums2.size()){
//             if(nums1[i] <= nums2[j]){
//                 maxi = max(maxi, j - i);
//                 j++;
//             } else {
//                 i++;
//                 if(i > j) j = i;
//             }
//         }
//         return maxi;
//     }
// };