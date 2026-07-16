class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        int n  = nums.size();
        int  maxi = INT_MIN;
        vector<int> preGCD;

        for(int i = 0;i < nums.size();i++){
            maxi = max(maxi,nums[i]);
            int temp = gcd(maxi,nums[i]);
            preGCD.push_back(temp);
        }

        sort(preGCD.begin(),preGCD.end());
        int i =0,j = n-1;
        long long sum = 0;

        while(i < j){
            
            int temp = gcd(preGCD[i++],preGCD[j--]);
            sum += temp;

        }
        return sum;
        
    }
};