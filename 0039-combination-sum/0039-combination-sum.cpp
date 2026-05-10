/*

    candidates = [2,3,6,7]
    target = 7


    "all unique combinations".............
    BACKTRACKING!!!!!!!!!!!!!!!!!!!!!

    goal : sum == target
    choice : take an element as much i want
    constraint : dont exceed target
    base case : hit target



    START :

    temp = []

    backtrack(0,7)



    ------------------------------------------------
    LEVEL 1
    ------------------------------------------------

    LOOP :

    i = 0 -> choose 2

    temp = [2]
    target = 5

    EXPLORE :

    backtrack(0,5)



        ------------------------------------------------
        LEVEL 2
        ------------------------------------------------

        temp = [2]

        LOOP :

        i = 0 -> choose 2

        temp = [2,2]
        target = 3

        EXPLORE :

        backtrack(0,3)



            ------------------------------------------------
            LEVEL 3
            ------------------------------------------------

            temp = [2,2]

            LOOP :

            i = 0 -> choose 2

            temp = [2,2,2]
            target = 1

            EXPLORE :

            backtrack(0,1)



                ------------------------------------------------
                LEVEL 4
                ------------------------------------------------

                temp = [2,2,2]

                LOOP :

                choose 2 -> exceeds target
                choose 3 -> exceeds target
                choose 6 -> exceeds target
                choose 7 -> exceeds target

                DEAD END

                RETURN



            UNDO CHOICE :

            temp = [2,2]



            ----------------------------------------
            continue loop
            ----------------------------------------

            i = 1 -> choose 3

            temp = [2,2,3]
            target = 0

            EXPLORE :

            backtrack(1,0)



                BASE CASE HIT !!!!!!!!

                target == 0

                ans.push_back([2,2,3])

                RETURN



            UNDO CHOICE :

            temp = [2,2]



            continue loop :

            choose 6 -> exceeds
            choose 7 -> exceeds

            RETURN



        UNDO CHOICE :

        temp = [2]



        ----------------------------------------
        continue loop
        ----------------------------------------

        i = 1 -> choose 3

        temp = [2,3]
        target = 2

        EXPLORE :

        backtrack(1,2)



            LOOP :

            choose 3 -> exceeds
            choose 6 -> exceeds
            choose 7 -> exceeds

            DEAD END

            RETURN



        UNDO CHOICE :

        temp = [2]



        continue loop :

        choose 6 -> exceeds
        choose 7 -> exceeds

        RETURN



    UNDO CHOICE :

    temp = []



    ------------------------------------------------
    continue LEVEL 1
    ------------------------------------------------

    i = 1 -> choose 3

    temp = [3]
    target = 4

    EXPLORE :

    backtrack(1,4)



        choose 3

        temp = [3,3]
        target = 1

        DEAD END

        RETURN



    UNDO :

    temp = []



    ------------------------------------------------

    i = 2 -> choose 6

    temp = [6]
    target = 1

    DEAD END

    RETURN

    UNDO :

    temp = []



    ------------------------------------------------

    i = 3 -> choose 7

    temp = [7]
    target = 0

    BASE CASE HIT !!!!!!!!

    ans.push_back([7])

    RETURN



    FINAL ANSWER :

    [
        [2,2,3],
        [7]
    ]




    IMPORTANT BACKTRACKING PATTERN :

    MAKE CHOICE
        ↓
    EXPLORE
        ↓
    UNDO CHOICE



    Example :

    temp.push_back(nums[i]);

    backtrack(...);

    temp.pop_back();

*/
class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int index, int target, vector<int>& nums) {

        // base case
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        // try every choice
        for(int i = index; i < nums.size(); i++) {

            // constraint
            if(nums[i] > target) continue;

            // make choice
            temp.push_back(nums[i]);

            // explore
            backtrack(i, target - nums[i], nums);

            // undo
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        backtrack(0, target, candidates);

        return ans;
    }
};