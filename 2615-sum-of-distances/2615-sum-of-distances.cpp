/*

    find all the nums elemnet index 
    map <number,list of index>

    then travserse again and for every nums[i] see in mapp 
    and calculate sum for every index 

        For each index → loop over all same indices  (slow)

    instead of this what can we do?????????

    Instead of computing distances again and again:

    Suppose indices of a number are:

    [1, 3, 6, 10]

    Now for index 6, distances:
    |6-1| + |6-3| + |6-10|

    Split into:

    Left side :
        (6-1) + (6-3)
        = 2*6 - (1+3)
    
    left  = k * idx[k] - sum_of_left

    Right side :
        (10-6)
        = (10) - 1*6

    right = (sum_of_right) - (n-k-1) * idx[k]

    then,
    ans[i] = left + right

    no need to calculate 6 bcoz |6-6| is 0

    only left and right side matters.........


1. Build map: num -> vector of indices
2. For each list:
    Compute prefix sum
    Loop over indices and apply formula



*/
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        //store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        // process 
        for (auto &it : mp) {
            vector<int> &v = it.second; //index list
            int m = v.size();

            // prefix sum
            vector<long long> pref(m, 0);
            pref[0] = v[0];

            //prefix of index list
            for (int i = 1; i < m; i++) {
                pref[i] = pref[i - 1] + v[i];
            } 

            //fill all the positions of an element...
            for (int i = 0; i < m; i++) {
                long long left = 0, right = 0;
                
                // v[i] is that index whose sum we finding now..
                if (i > 0)
                    left = (long long)i * v[i] - pref[i - 1];

                if (i < m - 1)
                    right = (pref[m - 1] - pref[i]) - (long long)(m - i - 1) * v[i];

                ans[v[i]] = left + right;
            }
        }

        return ans;
    }
};