/*

    x _ x
    minimum len can be 1

    bcoz, k can be be any non-negative power of 2
    means 0 1 2 3 4 ..........

    then,
    bcoz start element should be present 2 times
    and after that we find the square of it

    x
    x²
    x⁴
    ...
    peak
    ...
    x⁴
    x²
    x

    SO we can say that our answer len is alwyas ODD
    we trying to make odd len...
    then proceed further...........

    intution :

    1. Count frequency of every number

    2. Try every distinct number as the starting value x

    3. While current value has frequency >= 2,
    it can appear on both sides of the palindrome,
    so extend the pattern

    4. Move to current²

    5. The first value with frequency == 1 becomes the center

    6. If the next square doesn't exist, stop

    EDGE CASE :

        what if we have only array whch have only 1 
        [1,1,1,1,1,1,1,1,,1]

        then we stuck in infinite loop 

        so what can be the possible maximum len
        we know len is alwys ODD

        SO,
        then the maximum length is simply
`       freq[1] = f;
        f if f is odd.
        f - 1 if f is even.

        len = (f % 2 == 0) ? f - 1 : f;

*/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;

        for(int i=0;i < nums.size();i++){
            freq[nums[i]]++;
        }

        int ans = 1;

        int f = freq[1];
        int len = (f % 2 == 0) ? f - 1 : f;
        ans = max(ans,len);


        for (auto &[x, cnt] : freq)
        {
            if(x == 1) continue;
            // build pattern starting from x
            long long cur = x;
            int len = 0;

            while(freq[cur] >= 2){
                len += 2;

                if (!freq.count(cur * cur))
                    break;

                cur = cur * cur;
            }

            if(freq[cur] == 1){
                len++;
            }

            else{
                // No center exists at cur.
                // Convert the last pair into a center

                if(len > 0){
                    len--;
                }
                else{
                    len = 1;
                }
            }
            ans = max(ans,len);
        }
        return ans;
    }
};