/*
    we are intially on index 0

    each element in the array represents your maximum jump length at that position

    Return true if you can reach the last index, or false otherwise

    You are at index 0.

    At each index i, you can jump:
    0 → [1, 2, ..., nums[i]]
    So from i, you can reach up to:
        i +  nums[i]

    Instead of thinking:
    “Where should I jump next?”

    Think:

    “What is the maximum range I can reach so far?”

    If i > maxReach
    👉 You cannot even reach here ❌ → return false

    Otherwise:
    👉 You are safe, now expand your reach:

    maxReach = max(maxReach, i + nums[i]);
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++){

            if(i > maxReach) return false;

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};