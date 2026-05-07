/*
    For each index i,
    find the maximum value in nums that can be reached by
        following any sequence of valid jumps starting at i.

    Jump to index j where j > i is allowed only if nums[j] < nums[i].

    Jump to index j where j < i is allowed only if nums[j] > nums[i].

    Return an array ans where ans[i] is the maximum value reachable starting from index i.


    [2,3,1]



*/
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), suf(n), res(n);

        // prefix max
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
        }

        // suffix min
        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        res[n - 1] = pre[n - 1];

        // build answer
        for (int i = n - 2; i >= 0; i--) {

            // merge segment
            if (pre[i] > suf[i + 1]) {
                res[i] = res[i + 1];
            }

            // new segment
            else {
                res[i] = pre[i];
            }
        }

        return res;
    }
};