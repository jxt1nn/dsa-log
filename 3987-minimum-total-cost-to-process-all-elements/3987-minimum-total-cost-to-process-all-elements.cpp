class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();
        long long cost=0;
        long long cnt=0;
        long long a=k;
        const long long mod=1000000007;

        for(int i=0;i<n;i++){
            if(a<nums[i]){
                long long need=nums[i]-a;
                long long ops=(need+k-1)/k;

                a+=ops*k;

                long long st=cnt+1;
                long long l=cnt+ops;

                __int128 s=(__int128)ops*(st+l)/2;

                cnt+=ops;
                cost=(cost+(long long)(s%mod))%mod;
            }

            a-=nums[i];
        }

        return cost;
    }
};