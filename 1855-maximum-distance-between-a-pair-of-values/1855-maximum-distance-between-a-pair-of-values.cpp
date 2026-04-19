/*
    
    array is sorted in desecnding order...........

    left side always greater and right side always lower

    if we choose 9 from nums1 
    we can consider all element <= 9
    means 9 10 11 12 13 14...............

    and for that we can find the upper bound of nums[i]
    then check if j <= i 

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

    Because arrays are sorted (non-increasing):
        
        if condition fails once, it will keep failing further
        if condition works, you can try to push j further


    if(nums2[j] >= nums1[i]){
        we can try to expand j
    }
    else{
        we cannot go right becoz it will give us smaller 
        numbers beacuse of non-decreasing......

        so what we can do incerase the j
    }

    two pointers.....
    i = 0
    j = 0

    "For every i, push j as far as possible while condition holds"

*/
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int maxi = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                maxi = max(maxi, j - i);
                j++;
            } else {
                i++;
                if(i > j) j = i;
            }
        }
        return maxi;
    }
};