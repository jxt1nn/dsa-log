/*

we need to divide the array into k subsets
such that every subset has equal sum

RETURN TRUE IF POSSIBLE


first observation?????????????????

if(totalSum % k != 0){
    return false;
}

why??????????

because equal subsets are impossible


what will be the sum of ONE subset?????????

target = totalSum / k

example:

20 / 4 = 5

means every subset sum must become 5


IMPORTANT MINDSET SHIFT?????????????

DON'T THINK:

"generate all subsets"

THINK:

"where should current element go?????"


BACKTRACKING....................

means we try one possibility

if it fails later
UNDO IT
and try another possibility


bucket idea??????????????????

k subsets = k buckets


example:

k = 4

bucket0
bucket1
bucket2
bucket3


what do buckets store???????????

NOT elements

they store CURRENT SUM of subset


vector<int> bucket(k,0);

means:

bucket[i] = current sum of ith subset


initially:

[0,0,0,0]



what are the states?????????????

solve(index,bucket)

index  -> current element
bucket -> current sums of all subsets



what are the choices?????????????

suppose:

nums[index] = current number

choices:

put current number in bucket0
put current number in bucket1
put current number in bucket2
....

THIS creates recursion tree



example:

nums = [4,3,2,3,5,2,1]

target = 5


initially:

[0,0,0,0]


take 4:

[4,0,0,0]


now current number = 3

choices:

bucket0???

4+3 > 5 ❌


bucket1???

[4,3,0,0] ✅



now current number = 2

bucket0???

4+2 > 5 ❌


bucket1???

3+2 = 5 ✅

[4,5,0,0]



THIS IS RECURSION................


what is the validity condition?????????????

if(bucket[i] + nums[index] > target){

    invalid

}


otherwise valid choice



what is choose explore undo?????????????


CHOOSE:

bucket[i] += nums[index];


EXPLORE:

solve(index+1, nums, bucket, target)


UNDO:

bucket[i] -= nums[index];


why undo?????????????

because current choice may fail later

so we must go back
and try another bucket



example of BACKTRACKING?????????????


suppose:

bucket = [3,4,5]

current num = 6


3+6 > 6 ❌
4+6 > 6 ❌
5+6 > 6 ❌


current number fits nowhere

SO THIS PATH FAILED


return false


now recursion goes BACK

undo previous choice

and try another placement


THIS IS BACKTRACKING



VERY IMPORTANT QUESTION?????????????

how same element is not reused?????????????


because recursion processes ONLY ONE index at a time


after placing:

nums[index]

we move to:

solve(index+1,....)


so old element is never processed again


each element chooses exactly ONE bucket
in one recursive path



what is the base case?????????????


if(index == nums.size()){

    check every bucket sum

    if(all bucket sums == target){

        return true;
    }

    return false;
}



what happens if current number fits nowhere?????????????


loop finishes completely


means:

current recursive path failed


return false



loop structure?????????????


for(int i = 0; i < bucket.size(); i++){

    if(invalid){
        continue;
    }

    choose

    explore

    undo
}



MOST IMPORTANT INTUITION?????????????


THIS PROBLEM IS NOT:

subset generation


THIS PROBLEM IS:

ELEMENT ASSIGNMENT


Every recursive level asks:

"which subset should contain current element?"


THAT SINGLE THOUGHT
GENERATES THE WHOLE SOLUTION


*/
class Solution {
public:

    bool solve(int index,
               vector<int>& nums,
               vector<int>& bucket,
               int target) {

        // all numbers used
        if(index == nums.size()) {

            // every bucket must equal target
            for(int sum : bucket) {
                if(sum != target) {
                    return false;
                }
            }

            return true;
        }

        int num = nums[index];

        // try every bucket
        for(int i = 0; i < bucket.size(); i++) {

            // invalid
            if(bucket[i] + num > target) {
                continue;
            }

            // choose
            bucket[i] += num;

            // explore
            if(solve(index + 1, nums, bucket, target)) {
                return true;
            }

            // undo
            bucket[i] -= num;

            // optimization
            if(bucket[i] == 0) {
                break;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;

        for(int x : nums) {
            sum += x;
        }

        // impossible
        if(sum % k != 0) {
            return false;
        }

        int target = sum / k;

        vector<int> bucket(k, 0);

        return solve(0, nums, bucket, target);
    }
};