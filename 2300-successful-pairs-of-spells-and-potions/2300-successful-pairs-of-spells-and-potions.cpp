/*
    we have 2 arrays 
        spells and potions........

    size of n AND m 
        also a integer success

    A spell and potion pair is considered successful if the product of their strengths is at least success.

    spells = [5,1,3], potions = [1,2,3,4,5], success = 7
    answer  [4,0,3]
   
   
    if we go by brute 

    for every nums[i] we have to check for every elememt in potions

    for(int i = 0; i < n;i++){
        for(int j =0;j < m;j++){
            check
        }
    } 

    but this not optimal and give TLE...........

    what if we sort the potions array 

    bcoz when we check our condition 

    if(nums[i]  * nums[j] >= success) count++;


    but when this condition became true in sorted array 
    every other elemnt on left is also 
    follow this condition 
        we simply get the count by 

    m - j 


    this is drived from (r-l+1) 

    this manily use for count the subarray..........


    but how can we find this j ??????????

    if we do simple loop it will take O(n) in worst condition 

    but we have one more thing binary search 

    find the lower bound where this condition get statisfy 
    this will cost use O(log n)

    which is better/.........
*/
class Solution {
public:
    //binary search
    int solve(int num,vector<int>& p,long long success){
        int low = 0;
        int high = p.size()-1;

        int ans = p.size();        
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(1LL * p[mid] * num >= success){
                ans = mid;
                high  = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return p.size() - ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        vector<int> ans(n,0);

        sort(potions.begin(),potions.end());

        for(int i = 0 ; i < n; i++){
            ans[i] = solve(spells[i],potions,success);
        }
        return ans;
    }
};